// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerVolumeBox.generated.h"

UCLASS()
class PUZZLEMP_API ATriggerVolumeBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerVolumeBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private :

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerVolume;

	//create a TArray of AStaticMeshActor for activate and remove trigger function callbacks
	UPROPERTY(EditAnywhere, Category = "Triggers")
	TArray<class AMyStaticMeshActor*> ActorsToTrigger;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
