// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IKMove.generated.h"

UCLASS()
class THREEDMATH_API AIKMove : public AActor
{
	GENERATED_BODY()
	
public:	
	AIKMove();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove")
	class UStaticMeshComponent* Body;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove" )
	class USceneComponent* TargetPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKMove")
	USceneComponent* LeftLeg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove")
	UStaticMeshComponent* LeftUpper;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove")
	UStaticMeshComponent* LeftMiddle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove")
	UStaticMeshComponent* LeftLower;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKMove")
	UStaticMeshComponent* LeftEnd;
	
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKMove")
	//UArrowComponent* RightUpper;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKMove")
	//UArrowComponent* RightLower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

protected:
public:	
	UFUNCTION(BlueprintCallable)
	void InitSetup();

	UFUNCTION(BlueprintCallable)
	void IKSolver();

private:
	uint8 TotalSegments;
	float TotalLength;
	bool bHasInitialized;

	TArray<float> BonesLength;
	TArray<UStaticMeshComponent*> Bones;
	FVector Positions[4];
	int32 PositionsLength = 4;
	FRotator Rotations[4];

	FVector GetDirection(FVector TargetPos, FVector CurrentPos);
};
