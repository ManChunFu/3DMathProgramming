// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Orbiter.generated.h"

UCLASS()
class THREEDMATH_API AOrbiter : public AActor
{
	GENERATED_BODY()
	
public:	
	AOrbiter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sphere")
	class UStaticMeshComponent* Planet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sphere")
	class USceneComponent* RootSceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float Offset;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
};
