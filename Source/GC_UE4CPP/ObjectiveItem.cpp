
#include "BaseCharacter.h"
#include "PickableItem.h"
#include "ObjectiveItem.h"

// Sets default values
AObjectiveItem::AObjectiveItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Static Mesh Component as Root
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;

	SocketName = "ItemSocket";

	DestroyDelay = 2;

	Item = nullptr;
}

// Called when the game starts or when spawned
void AObjectiveItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectiveItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObjectiveItem::Interact(ABaseCharacter* character)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "Objective Item");
	if (!Item && character->PossessedObject)
	{
		Item = Cast<APickableItem>(character->PossessedObject);
		if (Item)
		{
			Item->LayItemOnStand(StaticMesh, SocketName);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "Item collected, destroying in few seconds");
			GetWorld()->GetTimerManager().SetTimer(TriggerDestroyTimerHandle, this, &AObjectiveItem::TriggerDestroy, DestroyDelay);
		}
	}
}

void AObjectiveItem::TriggerDestroy()
{
	Item->Destroy();
	Item = nullptr;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "Item destroyed");
}

