// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//function to host the server
	void SetMenuInterface(IMenuInterface* MenuInterface);

	//function to set the menu interface
	void Setup();

	//function to reverse setup when the menu is closed 
	void Teardown();

protected:

	IMenuInterface* MenuInterface;

};
