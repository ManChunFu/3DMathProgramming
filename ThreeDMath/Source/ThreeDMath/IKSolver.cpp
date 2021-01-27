// Fill out your copyright notice in the Description page of Project Settings.


#include "IKSolver.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

AIKSolver::AIKSolver()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetRelativeLocation(FVector(0.0f, 0.0f, -10.0f));
	Body->SetupAttachment(RootComponent);

#pragma region LeftFrontLimb

#pragma endregion

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

	RLinearArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("RLinearArrow"));
	RLinearArrow->SetupAttachment(RootComponent);

	RJoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RJoint"));
	RJoint->SetRelativeScale3D(FVector(0.2f));
	RJoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	RJoint->SetupAttachment(RootComponent);

	RUpperSegment = CreateDefaultSubobject<UArrowComponent>(TEXT("RUpperSegment"));
	RUpperSegment->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	RUpperSegment->SetupAttachment(RootComponent);

	RLowerSegment = CreateDefaultSubobject<UArrowComponent>(TEXT("RLowerSegment"));
	RLowerSegment->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
	RLowerSegment->SetupAttachment(RootComponent);

	RVerticalMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("RVerticalMarker"));
	RVerticalMarker->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	RVerticalMarker->SetupAttachment(RootComponent);

	REndPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("REndPoint"));
	REndPoint->SetRelativeScale3D(FVector(0.2f));
	REndPoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	REndPoint->SetupAttachment(RootComponent);


	LBJoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBJoint"));
	LBJoint->SetRelativeScale3D(FVector(0.2f));
	LBJoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	LBJoint->SetupAttachment(RootComponent);

	LBUpper = CreateDefaultSubobject<UArrowComponent>(TEXT("LBUpper"));
	LBUpper->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	LBUpper->SetupAttachment(RootComponent);

	LBLower = CreateDefaultSubobject<UArrowComponent>(TEXT("LBLower"));
	LBLower->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
	LBLower->SetupAttachment(RootComponent);

	LBEndPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBEndPoint"));
	LBEndPoint->SetRelativeScale3D(FVector(0.2f));
	LBEndPoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	LBEndPoint->SetupAttachment(RootComponent);

	RBJoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RBJoint"));
	RBJoint->SetRelativeScale3D(FVector(0.2f));
	RBJoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	RBJoint->SetupAttachment(RootComponent);

	RBUpper = CreateDefaultSubobject<UArrowComponent>(TEXT("RBUpper"));
	RBUpper->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	RBUpper->SetupAttachment(RootComponent);

	RBLower = CreateDefaultSubobject<UArrowComponent>(TEXT("RBLower"));
	RBLower->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
	RBLower->SetupAttachment(RootComponent);

	RBEndPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RBEndPoint"));
	RBEndPoint->SetRelativeScale3D(FVector(0.2f));
	RBEndPoint->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	RBEndPoint->SetupAttachment(RootComponent);


	//UpperArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperArm"));
	//UpperArm->SetRelativeLocation(FVector(100.0f, 60.0f, 0.0f));
	//UpperArm->SetupAttachment(RootComponent);

	//LowerArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LowerArm"));
	//LowerArm->SetRelativeLocation(FVector(340.0f, 60.0f, 0.0f));
	//LowerArm->SetupAttachment(RootComponent);

	UpperLength = 40.0f;
	LowerLength = 60.0f;
	IKOrigin = FVector(0.0f, 0.0f, 30.0f);
	LFTargetLocation = FVector(50.0f, -40.0f, 0.0f);
	LBTargetLocation = FVector(-50.0f, -40.0f, 0.0f);
	RFTargetLocation = FVector(50.0f, 40.0f, 0.0f);
	RBTargetLocation = FVector(-50.0f, 40.0f, 0.0f);

	BodyOffset = Body->GetRelativeLocation();
	CurrentPointIndex = 0;
	bIsReverse = false;
	MoveSteps = FVector(20.0f, 0.0f, 20.0f);
}

void AIKSolver::BeginPlay()
{
	Super::BeginPlay();
	
	//TargetLocation = FVector(50.0f, 0.0f, 0.0f);
	//IKOrigin = FVector(0.0f, 0.0f, 20.0f);
	//RTargetLocation = FVector(-50.0f, 0.0f, 0.0f);

	ActorOffset = GetActorLocation();

	if (bUseWaypoints)
	{
		if (Waypoints.Num() > 0)
		{
			TotalWaypoints = Waypoints.Num();

			UpdateNextPoint();
		}
	}
}

void AIKSolver::OnConstruction(const FTransform& Transform)
{
	AdjustLimbPosition(EMoveTypes::EMT_LeftFront);
	AdjustLimbPosition(EMoveTypes::EMT_RightBehind);
	AdjustLimbPosition(EMoveTypes::EMT_RightFront);
	AdjustLimbPosition(EMoveTypes::EMT_LeftBehind);
	AdjustLimbPosition(EMoveTypes::EMT_Body);
}

void AIKSolver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (bUseWaypoints)
	{
		if (CurrentWaypoint)
		{
			float DistanceToGoal = FVector::Distance(CurrentWaypoint->GetActorLocation(), Body->GetComponentLocation());
			if (DistanceToGoal < 100.0f)
				UpdateNextPoint();
			else
				MoveTo(DeltaTime, CurrentWaypoint->GetActorLocation());
		}
	}
	else 
	{
		if (Target)
		{
			float DistanceToGoal = FVector::Distance(Target->GetActorLocation(), Body->GetComponentLocation());
			UE_LOG(LogTemp, Warning, TEXT("%f"), DistanceToGoal);
			if (DistanceToGoal < 200.0f)
			{
				Stop();
				LFTargetLocation = FVector(RFTargetLocation.X, -RFTargetLocation.Y, 0.0f);
				AdjustLimbPosition(EMoveTypes::EMT_RightFront);
			}
			else
				MoveTo(DeltaTime, Target->GetActorLocation());

		}
	}
	
}

void AIKSolver::UpdateNextPoint()
{
	if (Waypoints.Num() < 1)
		return;

	if (CurrentPointIndex == TotalWaypoints - 1)
		bIsReverse = true;
	else if (CurrentPointIndex == 0)
		bIsReverse = false;

	CurrentWaypoint = (bIsReverse)? Waypoints[--CurrentPointIndex] : Waypoints[++CurrentPointIndex];
}

FVector AIKSolver::FindLinearEndPoint(FVector NormalizedDirection, FVector TargetPos, FVector Origin)
{
	float TotalUpperLowerLength = UpperLength + LowerLength; // Max length
											// Blueprint node name => VectorLengh
	float LengthFromTarget = FMath::Clamp(IKOffsetSolve(TargetPos, Origin).Size() / TotalUpperLowerLength, 0.0f, 1.0f) * TotalUpperLowerLength;

	FVector DistanceFromLength = NormalizedDirection * LengthFromTarget;
	
	return DistanceFromLength;
}

float AIKSolver::GetLengthOfAdjacent(FVector NormalizedDirection, FVector TargetPos, FVector Origin)
{
	float TotalUpperLowerLength = UpperLength + LowerLength;
	float PercentageOfUpperLength = UpperLength / TotalUpperLowerLength;


	float LengthOfAdjacent = FindLinearEndPoint(NormalizedDirection, TargetPos, Origin).Size() * PercentageOfUpperLength;// Adjacent

	return LengthOfAdjacent;
}

FVector AIKSolver::IKOffsetSolve(FVector Location, FVector Origin)
{
	// IK localized position
	return Location - Origin;
}

void AIKSolver::Movement()
{
	//FVector NormalizedDirection = IKOffsetSolve(TargetLocation, IKOrigin).GetSafeNormal(0.0001f);

	//FVector LinearEndPoint = FindLinearEndPoint(NormalizedDirection, TargetLocation, IKOrigin);
	//LinearArrow->ArrowLength = LinearEndPoint.Size(); // follow the target (linear visualize)

	//FVector EndPointLocation = LinearEndPoint + IKOrigin;
	//EndPoint->SetRelativeLocation(EndPointLocation);

	//FRotator RotationFromXVector = UKismetMathLibrary::MakeRotFromX(NormalizedDirection); // Blueprint node name -> RotationFromXVector
	//LinearArrow->SetRelativeLocationAndRotation(IKOrigin, RotationFromXVector);

	//float LengthOfAdjacent = GetLengthOfAdjacent(NormalizedDirection, TargetLocation, IKOrigin);
	//										//Hypotenuse
	//float OppositeOfUpperLength = FMath::Sqrt(FMath::Square(UpperLength) - FMath::Square(LengthOfAdjacent));
	//VerticalMarker->ArrowLength = OppositeOfUpperLength; // Marker height

	//FVector DistanceFromUpperLength = NormalizedDirection * LengthOfAdjacent;
	//FVector UpDirection = UKismetMathLibrary::GetUpVector(RotationFromXVector);
	//VerticalMarker->SetRelativeLocationAndRotation(DistanceFromUpperLength + IKOrigin, UKismetMathLibrary::MakeRotFromX(UpDirection));

	//FVector JointLocation = DistanceFromUpperLength + (UpDirection * OppositeOfUpperLength) + IKOrigin;
	//Joint->SetRelativeLocation(JointLocation); // Segment position

	//FRotator UpperRotation = UKismetMathLibrary::FindLookAtRotation(IKOrigin, JointLocation);
	//UpperSegment->SetRelativeLocationAndRotation(IKOrigin, UpperRotation);

	//FRotator LowerRotation = UKismetMathLibrary::FindLookAtRotation(JointLocation, EndPointLocation);
	//LowerSegment->SetRelativeLocationAndRotation(JointLocation, LowerRotation);

	//FVector UpperArmLocation = IKOrigin + (UpperRotation.Vector() * (FVector::Distance(IKOrigin, JointLocation))); // pivot is in the middle
	//FVector LowerArmLocation = JointLocation + (UKismetMathLibrary::Conv_RotatorToVector(LowerRotation) * (FVector::Distance(JointLocation, EndPointLocation)));

	//UpperArm->SetRelativeLocationAndRotation(UpperArmLocation, UpperRotation);
	//LowerArm->SetRelativeLocationAndRotation(LowerArmLocation, LowerRotation);
}

void AIKSolver::MovementT(UArrowComponent* Upper, UArrowComponent* Lower, UStaticMeshComponent* End, UStaticMeshComponent* Bone, FVector TargetPos)
{
	FVector NormalizedDirection = IKOffsetSolve(TargetPos, IKOrigin).GetSafeNormal(0.0001f);

	FVector LinearEndPoint = FindLinearEndPoint(NormalizedDirection, TargetPos, IKOrigin);

	FVector EndPointLocation = LinearEndPoint + IKOrigin;
	End->SetRelativeLocation(EndPointLocation);

	FRotator RotationFromXVector = UKismetMathLibrary::MakeRotFromX(NormalizedDirection); // Blueprint node name -> RotationFromXVector

	float LengthOfAdjacent = GetLengthOfAdjacent(NormalizedDirection, TargetPos, IKOrigin);
								//Hypotenuse
	float OppositeOfUpperLength = FMath::Sqrt(FMath::Square(UpperLength) - FMath::Square(LengthOfAdjacent));

	FVector DistanceFromUpperLength = NormalizedDirection * LengthOfAdjacent;
	FVector UpDirection = UKismetMathLibrary::GetUpVector(RotationFromXVector);

	FVector JointLocation = DistanceFromUpperLength + (UpDirection * OppositeOfUpperLength) + IKOrigin;
	Bone->SetRelativeLocation(JointLocation); // Segment position

	FRotator UpperRotation = UKismetMathLibrary::FindLookAtRotation(IKOrigin, JointLocation);
	Upper->SetRelativeLocationAndRotation(IKOrigin, UpperRotation);

	FRotator LowerRotation = UKismetMathLibrary::FindLookAtRotation(JointLocation, EndPointLocation);
	Lower->SetRelativeLocationAndRotation(JointLocation, LowerRotation);

}

void AIKSolver::UpdateInterp(EMoveTypes MoveType, FVector Value)
{
	switch (MoveType)
	{
	case EMoveTypes::EMT_LeftFront:
		if (bFirstTime)
		{
			bFirstTime = false;
			OriginTargetPos = LFTargetLocation;
		}
		LFTargetLocation = OriginTargetPos + Value;
		AdjustLimbPosition(EMoveTypes::EMT_LeftFront);
		break;
	case EMoveTypes::EMT_LeftBehind:
		if (bFirstTime)
		{
			bFirstTime = false;
			OriginTargetPos = LBTargetLocation;
		}
		LBTargetLocation = OriginTargetPos + Value;
		AdjustLimbPosition(EMoveTypes::EMT_LeftBehind);
		break;
	case EMoveTypes::EMT_Body:
		if (bFirstTime)
		{
			bFirstTime = false;
			OriginTargetPos = IKOrigin;
		}
		IKOrigin = OriginTargetPos + Value;
		AdjustLimbPosition(EMoveTypes::EMT_Body);
		break;
	case EMoveTypes::EMT_RightFront:
		if (bFirstTime)
		{
			bFirstTime = false;
			OriginTargetPos = RFTargetLocation;
		}
		RFTargetLocation = OriginTargetPos + Value;
		AdjustLimbPosition(EMoveTypes::EMT_RightFront);
		break;
	case EMoveTypes::EMT_RightBehind:
		if (bFirstTime)
		{
			bFirstTime = false;
			OriginTargetPos = RBTargetLocation;
		}
		RBTargetLocation = OriginTargetPos + Value;
		AdjustLimbPosition(EMoveTypes::EMT_RightBehind);
		break;
	}
}

void AIKSolver::MoveTo(float DeltaTime, FVector TargetPosition)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetPosition);
	
	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), LookAtRotation, DeltaTime, 1.0f);
	SetActorRotation(NewRotation);

	Move();

}

void AIKSolver::AdjustLimbPosition(EMoveTypes MoveType)
{
	switch (MoveType)
	{
	case EMoveTypes::EMT_LeftFront:
		MovementT(UpperSegment, LowerSegment, EndPoint, Joint, LFTargetLocation);
		break;
	case EMoveTypes::EMT_LeftBehind:
		MovementT(LBUpper, LBLower, LBEndPoint, LBJoint, LBTargetLocation);
		break;
	case EMoveTypes::EMT_Body:
		Body->SetRelativeLocation(BodyOffset + IKOrigin);
		break;
	case EMoveTypes::EMT_RightFront:
		MovementT(RUpperSegment, RLowerSegment, REndPoint, RJoint, RFTargetLocation);
		break;
	case EMoveTypes::EMT_RightBehind:
		MovementT(RBUpper, RBLower, RBEndPoint, RBJoint, RBTargetLocation);
		break;
	default:
		break;
	}
}





