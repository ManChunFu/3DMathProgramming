// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThreeDMathGameMode.h"
#include "ThreeDMathCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThreeDMathGameMode::AThreeDMathGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
