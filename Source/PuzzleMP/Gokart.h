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
	void ApplyRotation(float DeltaTime);

	FVector GetAirResistance();
	FVector GetRollingResistance();

	FVector Velocity;

	/*void MoveForward(float Value);
	void MoveRight(float Value);*/

	void MoveForward(float Value);
	void MoveRight(float Value);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveForward(float Value);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveRight(float Value);

	//mass of the kart, used to calculate acceleration and other physics related stuff in kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;
	
	float Throttle = 0;

	/*UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;*/

	UPROPERTY(EditAnywhere)
	float MinTurningRadius = 10;

	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015f;

	float SteeringThrow = 0;


	UPROPERTY(Replicated)
	FVector ReplicatedLocation;

	UPROPERTY(Replicated)
	FRotator ReplicatedRotation;

};
