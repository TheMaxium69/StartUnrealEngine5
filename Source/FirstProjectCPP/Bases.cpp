// Fill out your copyright notice in the Description page of Project Settings.


#include "Bases.h"

// Sets default values
ABases::ABases()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// LANCEMENT DE CE CODE A L'INITIALISATION DE LA CLASS

}

// Called when the game starts or when spawned
void ABases::BeginPlay()
{
	Super::BeginPlay();
	

	// LANCEMENT DE CE CODE AU LANCEMENT DU JEUX

	UE_LOG(LogTemp, Warning, TEXT("SALUT"), );




}

// Called every frame
void ABases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// LANCEMENT DE CE CODE A CHAQUE TICK (IMG), uniquement si le contrutor dit oui

}

