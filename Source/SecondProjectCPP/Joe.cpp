// Fill out your copyright notice in the Description page of Project Settings.


#include "Joe.h"

// Sets default values
AJoe::AJoe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJoe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJoe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJoe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

