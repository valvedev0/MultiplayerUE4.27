// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuUI.h"

UPuzzleGameInstance::UPuzzleGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Game Instance Constructor"));

	//use constructor helpers to find the class
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MenuSystem"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;
	MenuClass = MenuBPClass.Class;
}

void UPuzzleGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found UWidget Class %s"), *MenuClass->GetName());
}

void UPuzzleGameInstance::LoadMenu()
{
	//create a widget and add it to the viewport
	if (!ensure(MenuClass != nullptr)) return;
	Menu = CreateWidget<UMenuUI>(this, MenuClass);
	
	if (!ensure(Menu != nullptr)) return;
	
	Menu->Setup();
	Menu->SetMenuInterface(this);


}




void UPuzzleGameInstance::Host()
{

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}



void UPuzzleGameInstance::Join(const FString& Address)
{	

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

	UE_LOG(LogTemp, Warning, TEXT("JOINing game"));

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return; //any alternative to this null check? 


	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

}

