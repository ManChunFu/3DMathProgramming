// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turnet.generated.h"

UCLASS()
class THREEDMATH_API ATurnet : public AActor
{
	GENERATED_BODY()
	
public:	
	ATurnet();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow")
	class UArrowComponent* Base;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow")
	UArrowComponent* Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float BulletSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float TurnetHorizontalLimit;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Get normalized direction to the target
	FVector GetTargetDirection_Normalized();

	// Get rotation (only affects yaw-axis) of direction to the target
	FRotator GetAimTargetRotation();

	// Get rotation of direction to the target
	FRotator GetAimTargetElevation();

	FVector GetPredicTargetDirection_Normalized();

	float GetPredictTravelDistance(float Distance);
};
