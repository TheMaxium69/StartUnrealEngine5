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

	UE_LOG(LogTemp,Warning,TEXT("Salut je suis un actor"));
	
}

// Called every frame
void Abases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

