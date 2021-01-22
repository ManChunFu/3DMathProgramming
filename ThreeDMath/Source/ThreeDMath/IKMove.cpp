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
	LeftMiddle->SetupAttachment(LeftLeg);

	LeftLower = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftLower"));
	LeftLower->SetupAttachment(LeftLeg);

	LeftEnd = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftEnd"));
	LeftEnd->SetupAttachment(LeftLeg);


	//RightLegUpper = CreateDefaultSubobject<UArrowComponent>(TEXT("RightLegUpper"));
	//RightLegUpper->SetupAttachment(Parent);

	//RightLegLower = CreateDefaultSubobject<UArrowComponent>(TEXT("RightLegLower"));
	//RightLegLower->SetupAttachment(Parent);

	TotalSegments = 3;
	bHasInitialized = false;
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

	BonesLength.Add((LeftMiddle->GetRelativeLocation() - LeftUpper->GetRelativeLocation()).Size());
	BonesLength.Add((LeftLower->GetRelativeLocation() - LeftMiddle->GetRelativeLocation()).Size());
	BonesLength.Add((LeftEnd->GetRelativeLocation() - LeftLower->GetRelativeLocation()).Size());

	UE_LOG(LogTemp, Warning, TEXT("0: %f"), BonesLength[0]);
	UE_LOG(LogTemp, Warning, TEXT("1: %f"), BonesLength[1]);
	UE_LOG(LogTemp, Warning, TEXT("2: %f"), BonesLength[2]);

	for (uint8 index = 0; index < TotalSegments; index++)
	{
		TotalLength += BonesLength[index];
	}
}

void AIKMove::IKSolver()
{
	if (Bones.Num() < 0)
		return;

	for (int32 index = 0; index < Bones.Num(); index++)
	{
		Positions[index] = (Bones[index]->GetRelativeLocation());
	}
	

	if ((TargetLocation - Bones[0]->GetRelativeLocation()).SizeSquared() >= TotalLength * TotalLength)
	{
		FVector Direction = (GetDirection(TargetLocation, Positions[0]));
		// set everything after root (upper)
		for (int32 index = 1; index < PositionsLength; index++)
		{
			Positions[index] = Positions[index - 1] + Direction * BonesLength[index - 1];
		}
	}

	FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(TargetLocation, Positions[0]);
	for (int32 index = 0; index < PositionsLength; index++)
	{
		Bones[index]->SetRelativeLocationAndRotation(Positions[index], NewRotation);
	}
}

FVector AIKMove::GetDirection(FVector TargetPos, FVector CurrentPos)
{
	return (TargetPos - CurrentPos).GetSafeNormal(0.0001f);
}


