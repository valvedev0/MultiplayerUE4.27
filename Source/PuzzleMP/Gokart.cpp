// Fill out your copyright notice in the Description page of Project Settings.


#include "Gokart.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

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
	Force += GetAirResistance();
	Force += GetRollingResistance();

	FVector Acceleration = Force / Mass;
	Velocity = Velocity + Acceleration * DeltaTime;

	

	ApplyRotation(DeltaTime);


	UpdateLocationandVelocity(DeltaTime);


}

void AGokart::ApplyRotation(float DeltaTime)
{
	float DeltaLocation = FVector::DotProduct(GetActorForwardVector(), Velocity) * DeltaTime;
	float RotationAngle = DeltaLocation / MinTurningRadius * SteeringThrow;
	FQuat RotationDelta(GetActorUpVector(), RotationAngle);
	Velocity = RotationDelta.RotateVector(Velocity);
	AddActorWorldRotation(RotationDelta);
}

FVector AGokart::GetAirResistance()
{
	return -Velocity.GetSafeNormal() * Velocity.SizeSquared() * DragCoefficient;
}

FVector AGokart::GetRollingResistance()
{
	float AccelerationDueToGravity = -GetWorld()->GetGravityZ() / 100;
	float NormalForce = Mass * AccelerationDueToGravity;
	return -Velocity.GetSafeNormal() * RollingResistanceCoefficient * NormalForce;
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

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AGokart::Server_MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AGokart::Server_MoveRight);
}

void AGokart::Server_MoveForward_Implementation(float Value)
{
	//Velocity = GetActorForwardVector() * Value * 20;
	Throttle = Value;
}

bool AGokart::Server_MoveForward_Validate(float Value)
{
	return FMath::Abs(Value) <= 1;
}

void AGokart::Server_MoveRight_Implementation(float Value)
{
	SteeringThrow = Value;
}

bool AGokart::Server_MoveRight_Validate(float Value)
{
	return FMath::Abs(Value) <= 1;
}