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

	testNombre = 3;
	testDecimal = 5.16f;

	UE_LOG(LogTemp,Warning,TEXT("Salut je suis un actor"));
	UE_LOG(LogTemp,Warning,TEXT("Ma variable int = %d"), testNombre);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable float = %f"), testDecimal);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable Boolean = %d"), testBoolean);
	UE_LOG(LogTemp,Warning,TEXT("Ma variable Texte = %s"), *testString);

	myFunction();
	myFunction2(testNombre);
	int resultat = myFunction3(5, 9);
	UE_LOG(LogTemp,Warning,TEXT("Ma function additions int = %d"), resultat);
	int resultat2 = myFunction4(5);
	UE_LOG(LogTemp,Warning,TEXT("Ma function (default) additions int = %d"), resultat2);

	// testNombre = testNombre + 2;
	testNombre += 2;

	if (testNombre < 3)
	{
		UE_LOG(LogTemp,Warning,TEXT("Ma variable est infériere a 3"));
	}
	else if (testNombre == 3)
	{
		UE_LOG(LogTemp,Warning,TEXT("Ma variable est égal a 3"));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Ma variable est supérieur a 3"));
	}

}

// Called every frame
void Abases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// My Function
void Abases::myFunction()
{
	UE_LOG(LogTemp,Error,TEXT("Je suis dans ma function"));
}

void Abases::myFunction2(int N)
{
	N = N + 2;

	UE_LOG(LogTemp,Error,TEXT("Une additions = %d"), N);
}

int Abases::myFunction3(int N1, int N2)
{
	int N3 = N1 + N2;
	return N3;
}

int Abases::myFunction4(int N1, int N2)
{
	int N3 = N1 + N2;
	return N3;
}

