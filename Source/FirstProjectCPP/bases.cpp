// Fill out your copyright notice in the Description page of Project Settings.


#include "bases.h"

// Sets default values
Abases::Abases()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Abases::BeginPlay()
{
	Super::BeginPlay();

	testNombre = 5;
	testDecimal = 5.16f;

	UE_LOG(LogTemp,Warning,TEXT("Salut je suis un actor"));
	UE_LOG(LogTemp,Warning,TEXT("Ma variable int = %d"), testNombre);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable float = %d"), testDecimal);

}

// Called every frame
void Abases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

