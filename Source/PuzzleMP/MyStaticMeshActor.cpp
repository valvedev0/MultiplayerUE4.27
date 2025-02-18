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

void AMyStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	//set the replication for this actor to be true
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMyStaticMeshActor::ActivateTrigger()
{
	ActiveTriggers++;
}

void AMyStaticMeshActor::RemoveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}

void AMyStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//check if it has authority
	if (HasAuthority())
	{
		if (ActiveTriggers > 0)
		{

			//add actor location from one point to another
			FVector Location = GetActorLocation();

			//we will calculte the journey length from the start location to the target location and journey travelled 
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();  // GTL = 100 and GSL = 0, so the journey length is 100
			float JourneyTravelled = (Location - GlobalStartLocation).Size(); // if the actor is at 50, then the journey travelled is 50

			//swap the target location and start location if the journey travelled is greater than the journey length
			if (JourneyTravelled >= JourneyLength)
			{
				FVector Temp = GlobalStartLocation; //GSL = 0
				GlobalStartLocation = GlobalTargetLocation; //GSL = 100
				GlobalTargetLocation = Temp; //GTL = 0
			}

			//now we need to move our mesh to the target location, we will find the direction and normalize it. But before that we need to check if the target location is relative to the actor location.
			//FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); //here we are transforming the target location to the global target location so that we can find the direction of the target location in the global space
			FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}
}


