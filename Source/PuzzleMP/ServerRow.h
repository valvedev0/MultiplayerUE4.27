// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API UServerRow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;

	//create a setup fn with UMenuUI class and server index
	void Setup(class UMenuUI* Parent, uint32 Index);

private:

	//create a button
	UPROPERTY(meta = (BindWidget))
	class UButton* RowButton;

	//create a function for when the button is clicked
	UFUNCTION()
	void OnClicked();

	//getter and setter for the index and parent menu
	UPROPERTY()
	class UMenuUI* Parent;

	uint32 Index;



};
