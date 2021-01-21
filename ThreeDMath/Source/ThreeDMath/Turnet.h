// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turnet.generated.h"

UENUM(blueprintType)
enum class EAimPoint : uint8
{
	EAP_Head	 UMETA(DisplayName = "Head"),
	EAP_LeftArm  UMETA(DisplayName = "LeftArm"),
	EAP_RightArm UMETA(DisplayName = "RightArm"),
	EAP_LeftLeg  UMETA(DisplayName = "LeftLeg"),
	EAP_RightLeg UMETA(DisplayName = "RightLeg"),
	EAP_Body     UMETA(DisplayName = "Body")
};

UCLASS()
class THREEDMATH_API ATurnet : public AActor
{
	GENERATED_BODY()
	
public:	
	ATurnet();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turnet")
	class UStaticMeshComponent* Body;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turnet")
	class USceneComponent* Parent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turnet")
	class UArrowComponent* Base;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turnet")
	UArrowComponent* Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turnet")
	AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turnet")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turnet")
	float BulletSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turnet")
	float TurnetHorizontalLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turnet")
	EAimPoint AimPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bullet")
	TSubclassOf<class ABullet> Bullet;

	UFUNCTION(BlueprintImplementableEvent)
	void Shoot(FVector Velocity, float Speed);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsShooting;

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

	void PredictProjectilePath();

	void Move();

	TArray<FVector> UpdateTargetLocaiton();
	
	bool GetTargetLocation();

	class AThreeDMathCharacter* Player;
	FVector TargetLocation;
	
};
