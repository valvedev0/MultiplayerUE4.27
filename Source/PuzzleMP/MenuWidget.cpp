// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "PuzzleGameInstance.h"


void UMenuWidget::SetMenuInterface(IMenuInterface* InMenuInterface)
{
	this->MenuInterface = InMenuInterface;
}

void UMenuWidget::Setup()
{

	this->AddToViewport();

	this->bIsFocusable = true;

	//now we will set the input mode to the game and UI only and make use of Player Controller to set the input mode
	//get ref of the player controller
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//make use of the player controller to set the input mode and show the cursor 
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{
	this->RemoveFromViewport();

	//get ref of the player controller
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;

	//make use of the player controller to set the input mode and show the cursor 
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}