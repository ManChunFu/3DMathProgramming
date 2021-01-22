// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IKSolver.generated.h"

class UArrowComponent;
class UStaticMeshComponent;

UCLASS()
class THREEDMATH_API AIKSolver : public AActor
{
	GENERATED_BODY()
	
public:	
	AIKSolver();

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	//UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LinearArrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* Joint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* UpperSegment;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LowerSegment;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* VerticalMarker;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* EndPoint;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	//UStaticMeshComponent* UpperArm;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	//UStaticMeshComponent* LowerArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "IKSolver", Meta = (MakeEditWidget = true, ClampMin = "0.0", ClampMax = "100.0"))
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true, ClampMin = "0.0", ClampMax = "100.0"))
	FVector IKOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	float UpperLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	float LowerLength;

protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	FVector IKTarget;

	FVector FindLinearEndPoint(FVector NormalizedDirection);
	float GetLengthOfAdjacent(FVector NormalizedDirection);
	FVector IKOffsetSolve();

	UFUNCTION(BlueprintCallable)
	void UpdateUpperDirection(FVector Position);

	UFUNCTION(BlueprintCallable)
	void UpdateLowerDirection(FVector Position);
	void Movement();
};
