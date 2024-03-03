// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstProjectCPPGameMode.h"
#include "FirstProjectCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstProjectCPPGameMode::AFirstProjectCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
