// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MenuUI.generated.h"

/**
 * 
 */

 //create a struct to hold the server data like name and current players
USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;

};


UCLASS()
class PUZZLEMP_API UMenuUI : public UMenuWidget
{
	GENERATED_BODY()

public:

	UMenuUI(const FObjectInitializer& ObjectInitializer);

	//set the server list function
	void SetServerList(TArray<FServerData> ServerNames);
	
	//create a function to select a server index
	void SelectIndex(uint32 Index);


protected:
	virtual bool Initialize() override;

private:

	TSubclassOf<class UUserWidget> ServerRowClass;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();


	UFUNCTION()
	void OpenHostMenu();


	//crete twwo buttons host and join which will be binded to the buttons in the widget
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmJoinButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JOinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerHostName;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelHostMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmHostMenuButton;

	//UPROPERTY(meta = (BindWidget))
	//class UEditableTextBox* IPAddressField;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;

	//create a toptional variable for selected index
	TOptional<uint32> SelectedIndex;

	//create a function to update children
	void UpdateChildren();



	







	
};
