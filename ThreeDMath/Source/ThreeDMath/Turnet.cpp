// Fill out your copyright notice in the Description page of Project Settings.


#include "Turnet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ThreeDMathCharacter.h"
#include "Bullet.h"

ATurnet::ATurnet()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(RootComponent);

	Parent = CreateDefaultSubobject<USceneComponent>(TEXT("Parent"));
	Parent->SetupAttachment(Body);

	Base = CreateDefaultSubobject<UArrowComponent>(TEXT("Base"));
	Base->SetupAttachment(Parent);
	Barrel = CreateDefaultSubobject<UArrowComponent>(TEXT("Barrel"));
	Barrel->SetupAttachment(Parent);

	InterpSpeed = 2.0f;
	BulletSpeed = 100.0f; // 1 meter per second
	TurnetHorizontalLimit = 90.0f;
}

void ATurnet::BeginPlay()
{
	Super::BeginPlay();

	if (Target)
	{
		Player = Cast<AThreeDMathCharacter>(Target);
	}

}

void ATurnet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Player)
	{
		if (!GetTargetLocation())
			return;

		Move();

		FRotator BaseInterpRotation = FMath::RInterpTo(Base->GetRelativeRotation(), GetAimTargetRotation(), DeltaTime, InterpSpeed);
		Base->SetRelativeRotation(BaseInterpRotation);
		
		FRotator BarrelInterpRotation = FMath::RInterpTo(Barrel->GetRelativeRotation(), GetAimTargetElevation(), DeltaTime, InterpSpeed);
		Barrel->SetRelativeRotation(BarrelInterpRotation);

		PredictProjectilePath();
		
	}
}

FVector ATurnet::GetTargetDirection_Normalized()
{
	if (!Target)
		return FVector(0.0f);

	FVector Distance = Target->GetActorLocation() - Parent->GetComponentLocation();
	FVector Direction = (Parent->GetComponentRotation().UnrotateVector(Distance));

	return 	Distance.GetSafeNormal(0.0001f);
}

FRotator ATurnet::GetAimTargetRotation()
{
	FVector Direction = GetPredicTargetDirection_Normalized();
							// Blueprint node name -> RotationFromXVector
	FRotator AimRotation = UKismetMathLibrary::MakeRotFromX(Direction);
	AimRotation.Yaw = FMath::ClampAngle(AimRotation.Yaw, -TurnetHorizontalLimit, TurnetHorizontalLimit);

	AimRotation.Pitch = 0.0f;
	AimRotation.Roll = 0.0f;

	return AimRotation;
}

FRotator ATurnet::GetAimTargetElevation()
{
	FVector Direction = GetPredicTargetDirection_Normalized();
	float AimAngle = FMath::Atan2(Direction.Z, Direction.X);

	//Blueprint node name : MakeRotator
	FRotator NewRotation = Direction.Rotation();

	NewRotation.Pitch += AimAngle;
	NewRotation.Yaw = FMath::ClampAngle(NewRotation.Yaw, -TurnetHorizontalLimit, TurnetHorizontalLimit);
	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch, -10.0f, 90.0f); // Clamp the up and down (Y-axis)

	return NewRotation;
}

FVector ATurnet::GetPredicTargetDirection_Normalized()
{
	float Distance = FVector::Distance(TargetLocation/*Target->GetActorLocation()*/, GetActorLocation());

	FVector PredictTargetVelocity = Target->GetVelocity()* (BulletSpeed / Distance);
	FVector PredictTargetLocation = TargetLocation/*Target->GetActorLocation()*/ + PredictTargetVelocity;

	PredictTargetLocation.Z += GetPredictTravelDistance(Distance);

	FVector PredictDistance = PredictTargetLocation - GetActorLocation();
	FVector Direction = (Parent->GetComponentRotation().UnrotateVector(PredictDistance));

	return Direction.GetSafeNormal(0.0001f);
}

float ATurnet::GetPredictTravelDistance(float Distance)
{
	float TravelTime = Distance/ BulletSpeed;

	// Unreal unit = centemter. Unreal gravity => 980 center/sec
	return  FMath::Square(TravelTime) * -GetWorld()->GetGravityZ() * 0.5f;
}

void ATurnet::PredictProjectilePath()
{
	FPredictProjectilePathParams PredictParams;
	PredictParams.StartLocation = Barrel->GetComponentLocation();
										// Blueprint node name = GetRotationFromXVector
	PredictParams.LaunchVelocity = Barrel->GetComponentRotation().Vector() * BulletSpeed;
	PredictParams.bTraceWithChannel = true;
	PredictParams.bTraceWithCollision = true;
	PredictParams.TraceChannel = ECollisionChannel::ECC_WorldDynamic;
	PredictParams.DrawDebugType = EDrawDebugTrace::ForOneFrame;
	PredictParams.SimFrequency = 30.0f;
	PredictParams.MaxSimTime = 2.0f;
	
	FPredictProjectilePathResult OutPreditResult;
	
	UGameplayStatics::PredictProjectilePath(this, PredictParams, OutPreditResult);

	if (OutPreditResult.HitResult.bBlockingHit && !bIsShooting)
	{
		if (Cast<APawn>(OutPreditResult.HitResult.GetActor()))
			Shoot(PredictParams.LaunchVelocity, BulletSpeed);
	}
}


void ATurnet::Move()
{
	if (Target)
	{
		FVector Direction = Target->GetActorLocation() - GetActorLocation();
		FVector Normalized = Direction.GetSafeNormal(0.0001f);
		FRotator NewRotation = UKismetMathLibrary::MakeRotFromX(Normalized);
		NewRotation.Roll = 0.0f;
		NewRotation.Pitch = 0.0f;
		Body->SetRelativeRotation(NewRotation);
	}
}

TArray<FVector> ATurnet::UpdateTargetLocaiton()
{
	TArray<FVector> TargetPoints;
	USkeletalMeshComponent* PlayerMesh = Player->GetMesh();

	TargetPoints.Add(PlayerMesh->GetSocketLocation("Head"));
	TargetPoints.Add(PlayerMesh->GetSocketLocation("Chest"));
	TargetPoints.Add(PlayerMesh->GetSocketLocation("LeftWrist"));
	TargetPoints.Add(PlayerMesh->GetSocketLocation("RighWrist"));
	TargetPoints.Add(PlayerMesh->GetSocketLocation("LeftKnee"));
	TargetPoints.Add(PlayerMesh->GetSocketLocation("RightKnee"));

	return TargetPoints;
}

bool ATurnet::GetTargetLocation()
{
	TArray<FVector> TargetPoints = UpdateTargetLocaiton();

	FVector StartLocation = Barrel->GetComponentLocation();
	FHitResult Hit;

	for (auto Point : TargetPoints)
	{
		if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, Point, ECollisionChannel::ECC_GameTraceChannel1))
		{
			APawn* HitPawn = Cast<APawn>(Hit.GetActor());
			if (HitPawn)
			{
				TargetLocation = Point;
				return true;
			}
		}
	}
	return false;
}



