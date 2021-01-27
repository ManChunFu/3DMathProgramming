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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	FVector MoveSteps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver")
	bool bUseWaypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (EditCondition = "bUseWaypoints"))
	TArray<AActor*> Waypoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (EditCondition = "bUseWaypoints"))
	AActor* CurrentWaypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IKSolver", Meta = (EditCondition = "!bUseWaypoints"))
	AActor* Target;

	UPROPERTY(BlueprintReadWrite)
	bool bFirstTime = true;

protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	virtual void Tick(float DeltaTime) override;

	void UpdateNextPoint();

	UFUNCTION(BlueprintImplementableEvent)
	void Move();

	UFUNCTION(BlueprintImplementableEvent)
	void Stop();
private:
	FVector IKTarget;
	float UpperLength;
	float LowerLength;

	FVector FindLinearEndPoint(FVector NormalizedDirection, FVector TargetPos, FVector Origin);
	float GetLengthOfAdjacent(FVector NormalizedDirection, FVector TargetPos, FVector Origin);
	FVector IKOffsetSolve(FVector Location, FVector Origin);
	void Movement();

	UFUNCTION(BlueprintCallable)
	void MovementT(UArrowComponent* Upper, UArrowComponent* Lower, UStaticMeshComponent* End, UStaticMeshComponent* Bone, FVector TargetPos);

	UFUNCTION(BlueprintCallable)
	void UpdateInterp(EMoveTypes MoveType, FVector Value);

	FVector BodyOffset;
	FVector ActorOffset;

	FVector Direction;
	FVector OriginTargetPos;
	int32 TotalWaypoints;
	int32 CurrentPointIndex;
	bool bIsReverse;
	bool bHasReachedTarget;

	void MoveTo(float DeltaTime, FVector TargetPosition);

	void AdjustLimbPosition(EMoveTypes MoveType);
};
