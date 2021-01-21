// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ACannon::ACannon()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	// Camera
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	// Camera

	// Cannon
	CannonBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	CannonBodyMesh->SetupAttachment(RootComponent);

	CannonHeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadMesh"));
	CannonHeadMesh->SetupAttachment(CannonBodyMesh);

	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrelMesh"));
	BarrelMesh->SetupAttachment(CannonHeadMesh);
	BarrelMesh->SetRelativeRotation(FRotator(45.f, 0, 0));
	LaunchAngleInRad = 45.f * PI / 180.f;

	CannonMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	CannonMuzzle->SetupAttachment(BarrelMesh);
	// Cannon
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsGatheringPower)
	{
		LaunchSpeed += DeltaTime * PowerGatheringSpeed;
		LaunchPoint = CannonMuzzle->GetComponentLocation();

#pragma region Trajectory Debug
		for (int i = 1; i <= 30; i++)
		{
			float t = i / 10.f;
			float DisplacementX = LaunchSpeed * t * FMath::Cos(LaunchAngleInRad);
			float DisplacementY = LaunchSpeed * t * FMath::Sin(LaunchAngleInRad) - 0.5f * Gravity * t * t;
			FVector Forward = CannonHeadMesh->GetForwardVector();
			Forward *= DisplacementX * 100.f;
			FVector Up = CannonHeadMesh->GetUpVector();
			Up *= DisplacementY * 100.f;
			DrawDebugPoint(GetWorld(), LaunchPoint + Forward + Up, 5.f, FColor::Blue);
		}
#pragma endregion
	}
}

// Called to bind functionality to input
void ACannon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACannon::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACannon::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ACannon::CameraLookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ACannon::CameraTurn);

	PlayerInputComponent->BindAxis("LookUpBarrel", this, &ACannon::AdjustAngle);
	PlayerInputComponent->BindAxis("TurnBarrel", this, &ACannon::TurnBarrel);

	PlayerInputComponent->BindAction("CannonFire", IE_Pressed, this, &ACannon::StartGatheringPower);
	PlayerInputComponent->BindAction("CannonFire", IE_Released, this, &ACannon::EndGatheringPower);

	PlayerInputComponent->BindAction("CameraControl", IE_Pressed, this, &ACannon::StartMovingCamera);
	PlayerInputComponent->BindAction("CameraControl", IE_Released, this, &ACannon::EndMovingCamera);
}

void ACannon::AdjustAngle(float Value)
{
	if (Value == 0.f)
	{
		return;
	}

	float NewPitch = BarrelMesh->GetRelativeRotation().Pitch + Value * AngleAdjustingSpeed;
	NewPitch = FMath::ClampAngle(NewPitch, 0.f, 90.f);
	BarrelMesh->SetRelativeRotation(FRotator(NewPitch, 0, 0));

	LaunchAngleInRad = NewPitch * PI / 180.f;
}

void ACannon::TurnBarrel(float Value)
{
	if (Value == 0.f || bCanMoveCamera)
	{
		return;
	}

	CannonHeadMesh->SetRelativeRotation(CannonHeadMesh->GetRelativeRotation() + FRotator(0, Value * BarrelTurnSpeed, 0));
}

void ACannon::StartGatheringPower()
{
	bIsGatheringPower = true;
}

void ACannon::EndGatheringPower()
{
	bIsGatheringPower = false;

	BP_OnFire();
	LaunchSpeed = 0.f;
}

void ACannon::MoveForward(float Value)
{
	FVector Forward = CameraComp->GetForwardVector();
	Forward.Z = 0.f;
	RootComponent->AddWorldOffset(Forward * Value * MoveSpeed);
}

void ACannon::MoveRight(float Value)
{
	RootComponent->AddWorldOffset(CameraComp->GetRightVector() * Value * MoveSpeed);
}

void ACannon::StartMovingCamera()
{
	bCanMoveCamera = true;
}

void ACannon::EndMovingCamera()
{
	bCanMoveCamera = false;
}

void ACannon::CameraLookUp(float Value)
{
	if (bCanMoveCamera)
	{
		AddControllerPitchInput(Value);
	}
}

void ACannon::CameraTurn(float Value)
{
	if (bCanMoveCamera)
	{
		AddControllerYawInput(Value);
	}
}

