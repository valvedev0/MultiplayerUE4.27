// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStaticMeshActor.h"

AMyStaticMeshActor::AMyStaticMeshActor()
{
	//we need to check if the mesh is movable and has tick enabled
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bStartWithTickEnabled = true;

	//set the mesh to be movable
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}

void AMyStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//check if it has authority
	if (HasAuthority())
	{
		//add actor location from one point to another
		FVector Location = GetActorLocation();
		Location += FVector(Speed * DeltaTime, 0, 0);
		SetActorLocation(Location);
	}
}


