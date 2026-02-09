// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleMPGameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API ALobbyGameMode : public APuzzleMPGameMode
{
	GENERATED_BODY()

public:

	//using postlogin and logout to keep track of how many players are in the lobby and start the game when we have enough players

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

private:

	//number of players in the lobby
	uint32 NumPlayersInLobby = 0;

	
};
