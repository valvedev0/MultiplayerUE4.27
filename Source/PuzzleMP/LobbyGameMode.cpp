// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "TimerManager.h"

#include "PuzzleGameInstance.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumPlayersInLobby;

	if(NumPlayersInLobby >= 2)
	{
		//log a message to warn that 3 players have joined the lobby and the game will start
		UE_LOG(LogTemp, Warning, TEXT("2 players have joined the lobby. Starting the game..."));

		GetWorldTimerManager().SetTimer(GameStartTimer, this, &ALobbyGameMode::StartGame, 15.0f);
		
		
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumPlayersInLobby;
}

void ALobbyGameMode::StartGame()
{
	//cast the game instance to our puzzle game instance
	auto GameInstance = Cast<UPuzzleGameInstance>(GetGameInstance());

	if (GameInstance == nullptr) return;

	GameInstance->StartSession();

	//start the game by traveling to the main game map
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	//enable seamless travel
	bUseSeamlessTravel = true;
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");

}
