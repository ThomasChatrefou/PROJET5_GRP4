// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"
#include "Blueprint/UserWidget.h"

//lancement du jeux
void AMenu::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

	if (!MenuClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu class was not defined"));
		return;
	}


	Menu = CreateWidget(GetWorld(), MenuClass);
	if (!Menu)
	{
		UE_LOG(LogTemp, Warning, TEXT("Menu Class was not defined"));
		return;
	}

	Menu->AddToViewport();
	Menu->SetVisibility(ESlateVisibility::Visible);





}