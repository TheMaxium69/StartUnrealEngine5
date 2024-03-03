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
	UE_LOG(LogTemp,Warning,TEXT("Ma variable float = %f"), testDecimal);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable Boolean = %d"), testBoolean);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable Texte = %s"), *testString);

	myFunction();
	myFunction2(testNombre);
}

// Called every frame
void Abases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// My Function
void Abases::myFunction()
{
	UE_LOG(LogTemp,Warning,TEXT("Je suis dans ma function"));
}

void Abases::myFunction2(int N)
{
	N = N + 2;

	UE_LOG(LogTemp,Warning,TEXT("Une additions = %d"), N);
}

