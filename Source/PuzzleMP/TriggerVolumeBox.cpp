// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeBox.h"
#include "Components/BoxComponent.h"
#include "MyStaticMeshActor.h"

// Sets default values
ATriggerVolumeBox::ATriggerVolumeBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	RootComponent = TriggerVolume;



}

// Called when the game starts or when spawned
void ATriggerVolumeBox::BeginPlay()
{
	Super::BeginPlay();

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATriggerVolumeBox::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATriggerVolumeBox::OnOverlapEnd);
	
}

// Called every frame
void ATriggerVolumeBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerVolumeBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
	//loop through the array of actors to trigger
	for (AMyStaticMeshActor* Actor : ActorsToTrigger)
	{
		Actor->ActivateTrigger();
	}
}

void ATriggerVolumeBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
	//loop through the array of actors to trigger
	for (AMyStaticMeshActor* Actor : ActorsToTrigger)
	{
		Actor->RemoveTrigger();
	}
}

