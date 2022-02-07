// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolSpawnerDoor.generated.h"

UCLASS()
class GC_UE4CPP_API APatrolSpawnerDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolSpawnerDoor();


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Arch;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Door;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
