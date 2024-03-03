// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Joe.generated.h"

UCLASS()
class SECONDPROJECTCPP_API AJoe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJoe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	// Function

	void FunctionMoveFrontX(float Value);

	// Composants

		// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
		USpringArmComponent* mySpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
		UCameraComponent* myCamera;




};
