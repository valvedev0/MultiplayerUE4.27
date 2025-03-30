// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuUI.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"


bool UMenuUI::Initialize()
{
	bool Success = Super::Initialize();

	if (HostButton == nullptr) return false;
	HostButton->OnClicked.AddDynamic(this, &UMenuUI::HostServer);

	if (JoinButton == nullptr) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMenuUI::OpenJoinMenu);

	if (CancelJoinButton == nullptr) return false;
	CancelJoinButton->OnClicked.AddDynamic(this, &UMenuUI::OpenMainMenu);

	if (ConfirmJoinButton == nullptr) return false;
	ConfirmJoinButton->OnClicked.AddDynamic(this, &UMenuUI::JoinServer);


	if (!Success)
	{
		return false;
	}
	
	return true;
}

void UMenuUI::SetMenuInterface(IMenuInterface* InMenuInterface)
{
	this->MenuInterface = InMenuInterface;
}

void UMenuUI::Setup()
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

void UMenuUI::Teardown()
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
void UMenuUI::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}

	UE_LOG(LogTemp, Warning, TEXT("Hosting the server"));
}

void UMenuUI::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		const FString& Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
	}

	//create a log message when the join button is clicked that prints the address and confirms that the join button is clicked
	UE_LOG(LogTemp, Warning, TEXT("Joining the server"));


	
}

void UMenuUI::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JOinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JOinMenu);

}

void UMenuUI::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);

}


