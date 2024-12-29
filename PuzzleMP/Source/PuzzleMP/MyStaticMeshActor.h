// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMP_API AMyStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMyStaticMeshActor();

	//create a variable to store the speed of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	
	float Speed = 20.0f;

protected:

	virtual void Tick(float DeltaTime) override;	

	
};
