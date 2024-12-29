// Copyright Epic Games, Inc. All Rights Reserved.

#include "PuzzleMPGameMode.h"
#include "PuzzleMPCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzleMPGameMode::APuzzleMPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
