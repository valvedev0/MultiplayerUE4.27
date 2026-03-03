// Fill out your copyright notice in the Description page of Project Settings.


#include "Gokart.h"
#include "Components/InputComponent.h"

// Sets default values
AGokart::AGokart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGokart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGokart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Force = GetActorForwardVector() * Throttle * MaxDrivingForce;
	FVector Acceleration = Force / Mass;
	Velocity = Velocity + Acceleration * DeltaTime;



	UpdateLocationandVelocity(DeltaTime);


}

void AGokart::UpdateLocationandVelocity(float DeltaTime)
{
	FVector Translation = Velocity * DeltaTime * 100;

	FHitResult Hit;

	AddActorWorldOffset(Translation, true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		Velocity = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void AGokart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AGokart::MoveForward);

}

void AGokart::MoveForward(float Value)
{
	//Velocity = GetActorForwardVector() * Value * 20;
	Throttle = Value;
}

