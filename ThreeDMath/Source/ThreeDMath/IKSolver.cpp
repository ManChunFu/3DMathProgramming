// Fill out your copyright notice in the Description page of Project Settings.


#include "IKSolver.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

AIKSolver::AIKSolver()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	LinearArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("LinearArrow"));
	LinearArrow->SetupAttachment(RootComponent);

	Joint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Joint"));
	Joint->SetRelativeScale3D(FVector(0.2f));
	Joint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	Joint->SetupAttachment(RootComponent);

	UpperSegment = CreateDefaultSubobject<UArrowComponent>(TEXT("UpperSegment"));
	UpperSegment->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	UpperSegment->SetupAttachment(RootComponent);
	
	LowerSegment = CreateDefaultSubobject<UArrowComponent>(TEXT("LowerSegment"));
	LowerSegment->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
	LowerSegment->SetupAttachment(RootComponent);

	VerticalMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("VerticalMarker"));
	VerticalMarker->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	VerticalMarker->SetupAttachment(RootComponent);

	EndPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndPoint"));
	EndPoint->SetRelativeScale3D(FVector(0.2f));
	EndPoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	EndPoint->SetupAttachment(RootComponent);

	UpperArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperArm"));
	UpperArm->SetRelativeLocation(FVector(100.0f, 60.0f, 0.0f));
	UpperArm->SetupAttachment(RootComponent);

	LowerArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LowerArm"));
	LowerArm->SetRelativeLocation(FVector(340.0f, 60.0f, 0.0f));
	LowerArm->SetupAttachment(RootComponent);

	UpperLength = 60.0f;
	LowerLength = 60.0f;
	TargetLocation = FVector(0.0f);
	IKOrigin = FVector(0.0f);
	InterpSpeed = 5.0f;
}

void AIKSolver::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIKSolver::OnConstruction(const FTransform& Transform)
{
	Movement();
}

void AIKSolver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Movement();

}

FVector AIKSolver::FindLinearEndPoint(FVector NormalizedDirection)
{
	float TotalUpperLowerLength = UpperLength + LowerLength;
											// Blueprint node name => VectorLengh
	float LengthFromTarget = FMath::Clamp(IKOffsetSolve().Size() / TotalUpperLowerLength, 0.0f, 1.0f) * TotalUpperLowerLength;

	FVector DistanceFromLength = NormalizedDirection * LengthFromTarget;
	
	return DistanceFromLength;
}

float AIKSolver::GetLengthOfAdjacent(FVector NormalizedDirection)
{
	float TotalUpperLowerLength = UpperLength + LowerLength;
	float PercentageOfUpperLength = UpperLength / TotalUpperLowerLength;

	float LengthOfAdjacent = FindLinearEndPoint(NormalizedDirection).Size() * PercentageOfUpperLength;// Adjacent

	return LengthOfAdjacent;
}

FVector AIKSolver::IKOffsetSolve()
{
	// IK localized position
	return TargetLocation - IKOrigin;
}

void AIKSolver::UpdateUpperDirection(FVector Position)
{
	TargetLocation += Position;
	Movement();
}

void AIKSolver::UpdateLowerDirection(FVector Position)
{
	IKOrigin += Position;
	Movement();
	SetActorLocation(IKOrigin);
}

void AIKSolver::Movement()
{
	FVector NormalizedDirection = IKOffsetSolve().GetSafeNormal(0.0001f);

	FVector LinearEndPoint = FindLinearEndPoint(NormalizedDirection);
	LinearArrow->ArrowLength = LinearEndPoint.Size(); // follow the target (linear visualize)

	FVector EndPointLocation = LinearEndPoint + IKOrigin;
	EndPoint->SetRelativeLocation(EndPointLocation);

	FRotator RotationFromXVector = UKismetMathLibrary::MakeRotFromX(NormalizedDirection); // Blueprint node name -> RotationFromXVector
	LinearArrow->SetRelativeLocationAndRotation(IKOrigin, RotationFromXVector);

	float LengthOfAdjacent = GetLengthOfAdjacent(NormalizedDirection);
	//Hypotenuse
	float OppositeOfUpperLength = FMath::Sqrt(FMath::Square(UpperLength) - FMath::Square(LengthOfAdjacent));
	VerticalMarker->ArrowLength = OppositeOfUpperLength; // Marker height

	FVector DistanceFromUpperLength = NormalizedDirection * LengthOfAdjacent;
	FVector UpDirection = UKismetMathLibrary::GetUpVector(RotationFromXVector);
	VerticalMarker->SetRelativeLocationAndRotation(DistanceFromUpperLength + IKOrigin, UKismetMathLibrary::MakeRotFromX(UpDirection));

	FVector JointLocation = DistanceFromUpperLength + (UpDirection * OppositeOfUpperLength) + IKOrigin;
	Joint->SetRelativeLocation(JointLocation); // Segment position

	FRotator UpperRotation = UKismetMathLibrary::FindLookAtRotation(IKOrigin, JointLocation);
	UpperSegment->SetRelativeLocationAndRotation(IKOrigin, UpperRotation);

	FRotator LowerRotation = UKismetMathLibrary::FindLookAtRotation(JointLocation, EndPointLocation);
	LowerSegment->SetRelativeLocationAndRotation(JointLocation, LowerRotation);

	FVector UpperArmLocation = IKOrigin + (UpperRotation.Vector() * (FVector::Distance(IKOrigin, JointLocation))); // pivot is in the middle
	FVector LowerArmLocation = JointLocation + (UKismetMathLibrary::Conv_RotatorToVector(LowerRotation) * (FVector::Distance(JointLocation, EndPointLocation)));

	UpperArm->SetRelativeLocationAndRotation(UpperArmLocation, UpperRotation);
	LowerArm->SetRelativeLocationAndRotation(LowerArmLocation, LowerRotation);
}


