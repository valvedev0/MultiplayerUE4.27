// Fill out your copyright notice in the Description page of Project Settings.


#include "Gokart.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Net/UnrealNetwork.h"



// Sets default values
AGokart::AGokart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

// Called when the game starts or when spawned
void AGokart::BeginPlay()
{
	Super::BeginPlay();

	
}

void AGokart::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGokart, ReplicatedLocation);
	DOREPLIFETIME(AGokart, ReplicatedRotation);
}

FString GetEnumText(ENetRole Role)
{
	switch (Role)
	{
	case ROLE_None:
		return "None";
	case ROLE_SimulatedProxy:
		return "SimulatedProxy";
	case ROLE_AutonomousProxy:
		return "AutonomousProxy";
	case ROLE_Authority:
		return "Authority";
	default:
		return "ERROR";
	}
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

	if (HasAuthority())
	{
		ReplicatedLocation = GetActorLocation();
		ReplicatedRotation = GetActorRotation();
	}
	else
	{
		SetActorLocation(ReplicatedLocation);
		SetActorRotation(ReplicatedRotation);
	}

	//use getrole to display the role of the actor in the network, this is useful for debugging and understanding how the actor is replicated across the network
	FString RoleString = GetEnumText(GetLocalRole());
	DrawDebugString(GetWorld(), FVector(0, 0, 100), RoleString, this, FColor::White, DeltaTime);
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

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AGokart::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AGokart::MoveRight);
}

void AGokart::MoveForward(float Value)
{
	Throttle = Value;
	Server_MoveForward(Value);
}


void AGokart::MoveRight(float Value)
{
	SteeringThrow = Value;
	Server_MoveRight(Value);
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