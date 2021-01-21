// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Cannon.generated.h"

class UBoxComponent;
class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class THREEDMATH_API ACannon : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* CannonBodyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* CannonHeadMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* BarrelMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	USceneComponent* CannonMuzzle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	float AngleAdjustingSpeed = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	float BarrelTurnSpeed = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	float PowerGatheringSpeed = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	float Gravity = 9.81f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
	float MoveSpeed = 2.f;

	FVector LaunchVelocity;
	FVector LaunchPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cannon)
	float LaunchSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cannon)
	float LaunchAngleInRad;

	bool bIsGatheringPower;
	bool bCanMoveCamera;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void AdjustAngle(float Value);

	UFUNCTION()
	void TurnBarrel(float Value);

	UFUNCTION()
	void CameraLookUp(float Value);

	UFUNCTION()
	void CameraTurn(float Value);

	UFUNCTION()
	void StartGatheringPower();

	UFUNCTION()
	void EndGatheringPower();

	UFUNCTION()
	void StartMovingCamera();

	UFUNCTION()
	void EndMovingCamera();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnFire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
