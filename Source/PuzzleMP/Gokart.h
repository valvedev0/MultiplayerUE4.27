// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Gokart.generated.h"

UCLASS()
class PUZZLEMP_API AGokart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGokart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void UpdateLocationandVelocity(float DeltaTime);

	FVector Velocity;

	void MoveForward(float Value);

	//mass of the kart, used to calculate acceleration and other physics related stuff in kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;
	
	float Throttle = 0;

};
