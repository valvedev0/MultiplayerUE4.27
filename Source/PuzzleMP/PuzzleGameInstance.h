// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API UPuzzleGameInstance : public UGameInstance
{
	GENERATED_BODY()

	//create constructor
	UPuzzleGameInstance(const FObjectInitializer& ObjectInitializer);

	//create function to initialize the game instance
	virtual void Init();

	//create function to host a game
	UFUNCTION(Exec)
	void Host();

	//create function to join a game
	UFUNCTION(Exec)
	void Join(const FString& Address);
	
};
