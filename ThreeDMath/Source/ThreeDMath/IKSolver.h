// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IKSolver.generated.h"

class UArrowComponent;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMoveTypes : uint8
{
	EMT_LeftFront    UMETA(DisplayName = "LeftFront"),
	EMT_LeftBehind  UMETA(Displayname = "LeftBehind"),
	EMT_Body		UMETA(DisplayName = "Body"),
	EMT_RightFront   UMETA(DisplayName = "RightFront"),
	EMT_RightBehind UMETA(DisplayName = "RightBehind")
};

UCLASS()
class THREEDMATH_API AIKSolver : public AActor
{
	GENERATED_BODY()
	
public:	
	AIKSolver();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* Body;

#pragma region LeftFrontLimb
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LinearArrow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* Joint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* UpperSegment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LowerSegment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* VerticalMarker;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* EndPoint;
#pragma endregion

#pragma region RightFrontLimb
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RLinearArrow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* RJoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RUpperSegment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RLowerSegment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RVerticalMarker;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* REndPoint;
#pragma endregion

#pragma region LeftBehindLimb
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* LBJoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LBUpper;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* LBLower;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* LBEndPoint;
#pragma endregion

#pragma region RightBehindLimb
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* RBJoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RBUpper;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UArrowComponent* RBLower;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "IKSolver")
	UStaticMeshComponent* RBEndPoint;
#pragma endregion


	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	//UStaticMeshComponent* UpperArm;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IKSolver")
	//UStaticMeshComponent* LowerArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	EMoveTypes MoveTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true))
	FVector IKOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "IKSolver", Meta = (MakeEditWidget = true))
	FVector LFTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true))
	FVector LBTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true))
	FVector RFTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (MakeEditWidget = true))
	FVector RBTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StepScale;

	UPROPERTY(BlueprintReadWrite)
	FVector StartPosition;

	UPROPERTY(BlueprintReadWrite)
	FVector EndPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	float UpperLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	float LowerLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bFirstTime = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MoveSteps;

	UPROPERTY(BlueprintReadWrite)
	FVector Direction;


	UPROPERTY(BlueprintReadOnly)
	FVector BodyOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	TArray<AActor*> Waypoints;

	UPROPERTY(BlueprintReadWrite)
	AActor* CurrentWaypoint;
protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	virtual void Tick(float DeltaTime) override;

	void MoveToNextPoint();

	UFUNCTION(BlueprintImplementableEvent)
	void Move();
private:
	FVector IKTarget;

	FVector FindLinearEndPoint(FVector NormalizedDirection, FVector TargetPos, FVector Origin);
	float GetLengthOfAdjacent(FVector NormalizedDirection, FVector TargetPos, FVector Origin);
	FVector IKOffsetSolve(FVector Location, FVector Origin);

	UFUNCTION(BlueprintCallable)
	void Movement();
	UFUNCTION(BlueprintCallable)
	void MovementT(UArrowComponent* Upper, UArrowComponent* Lower, UStaticMeshComponent* End, UStaticMeshComponent* Bone, FVector TargetPos);

	UFUNCTION(BlueprintCallable)
	void UpdateInterp(EMoveTypes MoveType, FVector Value);

	UPROPERTY(EditAnywhere)
	FVector OriginTargetPos;

	uint8 TotalWaypoints;
	uint8 CurrentPointIndex;
	bool bIsReverse;


	FVector GetDirection(FVector TargetPos, FVector Current);
};
