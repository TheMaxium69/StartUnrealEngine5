// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Joe.h"
#include "Animation/AnimInstance.h"
#include "AN_Joe.generated.h"

/**
 * 
 */
UCLASS()
class SECONDPROJECTCPP_API UAN_Joe : public UAnimInstance
{
	GENERATED_BODY()

protected:
	// Recupere cette function
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	AActor* Acteur;
	AJoe* Joe;

	UPROPERTY(BlueprintReadWrite, Category="walk")
		float Speed;

};
