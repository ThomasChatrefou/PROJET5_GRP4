// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPatrol.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"


// Detection + call functions when you've been see
AAIPatrol::AAIPatrol()
{
	// Initialize Senses
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);

}

void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();
	
	// if player is caught, call the OnPlayerCaught function
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIPatrol::OnPlayerCaught);
	}
}

void AAIPatrol::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Allow the AIPatrolController to possess the AIPatrol
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIPatrol::OnPlayerCaught(APawn* Pawn)
{
	// Get a reference to the player controller
	AAIPatrolController* AIController = Cast<AAIPatrolController>(GetController());

	// Cast succesful ?
	if (AIController)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("You have been see!"));
		// Call the function SetPlayerCaught in AIPatrolController
		AIController->SetPlayerCaught(Pawn);
	}
}

