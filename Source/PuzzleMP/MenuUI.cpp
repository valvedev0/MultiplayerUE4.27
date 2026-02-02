// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuUI.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "UObject/ConstructorHelpers.h"
#include "ServerRow.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"


UMenuUI::UMenuUI(const FObjectInitializer& ObjectInitializer)
{
	//use constructor helpers to create the BP class for the server row
	ConstructorHelpers::FClassFinder<UUserWidget> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	if (!ensure(ServerRowBPClass.Class != nullptr)) return;
	ServerRowClass = ServerRowBPClass.Class;
}

void UMenuUI::SetServerList(TArray<FString> ServerNames)
{
	UWorld* World = this->GetWorld();
	if (!ensure(World != nullptr)) return;

	//clear  existing server rows before adding new ones
	ServerList->ClearChildren();

	//initialise an index variable and using a for loop to create server rows
	uint32 i = 0;

	//loop through the server names and create a server row for each one
	for (const FString& ServerName : ServerNames)
	{
		UServerRow* Row = CreateWidget<UServerRow>(World, ServerRowClass);
		if (!ensure(Row != nullptr)) return;
		
		Row->ServerName->SetText(FText::FromString(ServerName));
		Row->Setup(this, i);
		++i;

		ServerList->AddChild(Row);
	}
	

}


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


void UMenuUI::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}

	UE_LOG(LogTemp, Warning, TEXT("Hosting the server"));
}


void UMenuUI::SelectIndex(uint32 Index)
{
	SelectedIndex = Index;
	//UE_LOG(LogTemp, Warning, TEXT("Selected index: %d"), SelectedIndex);
}



void UMenuUI::JoinServer()
{
	if(SelectedIndex.IsSet())
	{
		UE_LOG(LogTemp, Warning, TEXT("Selected index: %d"), SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No index selected"));
		
	}


	if (MenuInterface != nullptr)
	{
		/*const FString& Address = IPAddressField->GetText().ToString();*/
		MenuInterface->Join("");
	}

	



	//create a log message when the join button is clicked that prints the address and confirms that the join button is clicked
	UE_LOG(LogTemp, Warning, TEXT("Joining the server"));


	
}

void UMenuUI::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JOinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JOinMenu);

	//refresh the server list when the join menu is opened
	if (MenuInterface != nullptr)
	{
		MenuInterface->RefreshServerList();
	}

}

void UMenuUI::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);

}


