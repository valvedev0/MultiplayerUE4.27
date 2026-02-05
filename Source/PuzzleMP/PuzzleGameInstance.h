// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "Interfaces/OnlineSessionInterface.h"


#include "OnlineSubsystem.h"
#include "PuzzleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API UPuzzleGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:

	//create constructor
	UPuzzleGameInstance(const FObjectInitializer& ObjectInitializer);

	//create function to initialize the game instance
	virtual void Init();

	//create function to host a game
	UFUNCTION(Exec)
	void Host(FString ServerName) override;

	//create a load menu funmction that is blueprint callable and will be used to load the menu in the main menu map
	UFUNCTION(BlueprintCallable)
	void LoadMenu(); 

	//create a load in game menu function that is blueprint callable and will be used to load the in game menu in the main menu map
	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	//create function to join a game
	UFUNCTION(Exec)
	void Join(uint32 Index) override;

	virtual void LoadMainMenu() override;

	//refresh server list override
	void RefreshServerList() override;

private:

	//create a subclass for the main menu which is of UserWidget type and we will make use of contrucion helpers to use the class finder
	TSubclassOf<class UUserWidget> MenuClass;

	//create a subclass for the in game menu which is of UserWidget type and we will make use of contrucion helpers to use the class finder
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UMenuUI* Menu;


	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	void CreateSession();

	FString DesiredServerName;
	

	
};
