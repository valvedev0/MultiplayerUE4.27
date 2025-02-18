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

	virtual void BeginPlay() override;


	//create a variable to store the speed of the actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float Speed = 20.0f;

	//create a target location for the actor to move to with gizmo properties in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = true))
	FVector TargetLocation = FVector(0, 0, 0);

	void ActivateTrigger();
	void RemoveTrigger();

protected:

	virtual void Tick(float DeltaTime) override;	

private :

	//now we will create two variable to move the actor from one point to another and then back to the original point
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
	
	//this will be used to activate the movement of the actor
	UPROPERTY(EditAnywhere, Category = "Triggers")
	int ActiveTriggers = 1;
};
