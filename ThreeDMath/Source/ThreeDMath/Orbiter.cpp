// Fill out your copyright notice in the Description page of Project Settings.


#include "Orbiter.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"


AOrbiter::AOrbiter()
{
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = RootSceneComponent;

	Planet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Planet"));
	Planet->SetupAttachment(RootComponent);

	Radius = 360.0f;
	Offset = 800.0f;

}

void AOrbiter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOrbiter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


