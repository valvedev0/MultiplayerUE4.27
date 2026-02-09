// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumPlayersInLobby;

	if(NumPlayersInLobby >= 3)
	{
		//log a message to warn that 3 players have joined the lobby and the game will start
		UE_LOG(LogTemp, Warning, TEXT("3 players have joined the lobby. Starting the game..."));

		//start the game by traveling to the main game map
		UWorld* World = GetWorld();
		if (!ensure(World != nullptr)) return;

		//enable seamless travel
		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
		
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumPlayersInLobby;
}
