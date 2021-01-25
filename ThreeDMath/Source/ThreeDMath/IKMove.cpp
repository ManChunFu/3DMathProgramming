// Fill out your copyright notice in the Description page of Project Settings.


#include "IKMove.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AIKMove::AIKMove()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(RootComponent);

	TargetPoint = CreateDefaultSubobject<USceneComponent>(TEXT("TargetPoint"));
	TargetPoint->SetupAttachment(Body);

	LeftLeg = CreateDefaultSubobject<USceneComponent>(TEXT("LeftLeg"));
	LeftLeg->SetupAttachment(Body);

	LeftUpper = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftUpper"));
	LeftUpper->SetupAttachment(LeftLeg);

	LeftMiddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftMiddle"));
	LeftMiddle->SetupAttachment(LeftUpper);

	LeftLower = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftLower"));
	LeftLower->SetupAttachment(LeftMiddle);

	LeftEnd = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftEnd"));
	LeftEnd->SetupAttachment(LeftLower);


	//RightLegUpper = CreateDefaultSubobject<UArrowComponent>(TEXT("RightLegUpper"));
	//RightLegUpper->SetupAttachment(Parent);

	//RightLegLower = CreateDefaultSubobject<UArrowComponent>(TEXT("RightLegLower"));
	//RightLegLower->SetupAttachment(Parent);

	TotalSegments = 3;
	bHasInitialized = false;
	MovementPerFrame = 10;
	StopLimit = 0.001f;
}


void AIKMove::InitSetup()
{
	if (bHasInitialized)
		return;

	bHasInitialized = true;
	// from up to down as the order of 0, 1, 2, 3
	Bones.Add(LeftUpper);
	Bones.Add(LeftMiddle);
	Bones.Add(LeftLower);
	Bones.Add(LeftEnd);

	Positions.Add(LeftUpper->GetRelativeLocation());
	Positions.Add(LeftMiddle->GetRelativeLocation());
	Positions.Add(LeftLower->GetRelativeLocation());
	Positions.Add(LeftEnd->GetRelativeLocation());

	PositionsLength = Positions.Num();

	BonesLength.Add((LeftMiddle->GetRelativeLocation() - LeftUpper->GetRelativeLocation()).Size());
	BonesLength.Add((LeftLower->GetRelativeLocation() - LeftMiddle->GetRelativeLocation()).Size());
	BonesLength.Add((LeftEnd->GetRelativeLocation() - LeftLower->GetRelativeLocation()).Size());

	for (uint8 index = 0; index < TotalSegments; index++)
	{
		TotalLength += BonesLength[index];
	}
}

void AIKMove::IKSolver()
{
	if (!bHasInitialized)
	{
		InitSetup();
		
		return;
	}

	if ((TargetLocation - Bones[0]->GetRelativeLocation()).SizeSquared() <= TotalLength * TotalLength)
	//	if ((TargetLocation - Bones[0]->GetRelativeLocation()).Size() >= TotalLength )

	{
		// strech 
		FVector Direction = (GetDirection(TargetLocation, Positions[0]));
		// set everything after root (upper)
		for (int32 index = 1; index < PositionsLength; index++)
		{
			Positions[index] = Positions[index - 1] + Direction * BonesLength[index - 1];
		}
	}
	else
	{
		for (int32 iteration = 0; iteration < MovementPerFrame; iteration++)
		{
			// doesn't move the upper bone
			for ( int32 index = PositionsLength -1;  index > 0; index--)
			{
				if (index == PositionsLength - 1)
					Positions[index] = TargetLocation; // set it to target
				else
					Positions[index] = Positions[index + 1] + GetDirection(Positions[index], Positions[index + 1]) * BonesLength[index]; // set in line on distance
			}

			for (int32 index = 1; index < PositionsLength; index++)
			{
				Positions[index] = Positions[index - 1] + GetDirection(Positions[index], Positions[index - 1]) * BonesLength[index - 1];
			}
			// close enough?
			if ((Positions[PositionsLength - 1] - TargetLocation).SizeSquared() < StopLimit * StopLimit)
				break;
		}
	}

	//for (int32 index = 1; index < PositionsLength -1; index++)
	//{
	//	auto Plane = FPlane({ GetDirection(Positions[index + 1], Positions[index -1]), Positions[index - 1] });
	//	auto ProjectedTargetPoint = FVector::PointPlaneProject(TargetPoint->GetRelativeLocation(), Plane);
	//	auto ProjectedBone = FVector::PointPlaneProject(Positions[index], Plane);
	//	auto AngleInRadius = FMath::Acos(FVector::DotProduct(GetDirection(ProjectedBone, Positions[index - 1]), GetDirection(ProjectedTargetPoint, Positions[index - 1])));
	//	auto AngleInDegress = FMath::RadiansToDegrees(AngleInRadius);
	//	FVector Pos = Positions[index].RotateAngleAxis(AngleInDegress, Plane.GetNormal()) * (Positions[index] - Positions[index - 1] + Positions[index - 1]);
	//	Positions[index] = Pos;
	//}

	for (int32 index = 0; index < PositionsLength; index++)
	{
		FRotator NewRotation = (index == PositionsLength -1) ? GetRotation(TargetLocation, Positions[index]) : GetRotation(Positions[index + 1], Positions[index]);
		Bones[index]->SetRelativeLocationAndRotation(Positions[index], NewRotation);
	}
}

FVector AIKMove::GetDirection(FVector TargetPos, FVector CurrentPos)
{
	return (TargetPos - CurrentPos).GetSafeNormal(0.0001f);
}

FRotator AIKMove::GetRotation(FVector TargetPos, FVector CurrentPos)
{
	return UKismetMathLibrary::FindLookAtRotation(TargetPos, CurrentPos);
}


