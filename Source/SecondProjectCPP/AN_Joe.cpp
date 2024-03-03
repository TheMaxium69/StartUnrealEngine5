// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_Joe.h"

void UAN_Joe::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	Acteur = GetOwningActor();
	if (Acteur)
	{
		Joe = Cast<AJoe>(Acteur);

		if (Joe)
		{

			Speed = Joe->VSpeed;

		}

	}
}
