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

	// Variable

	float TheDeltaTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InputCamera")
	float VitesseHorz = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InputCamera")
	float VitesseVert = 60.f;


	// Function

	void FunctionMoveFrontX(float Value);
	void FunctionMoveY(float Value);
	void FunctionRotate(float Value);
	void FunctionLookUpDown(float Value);
	void FunctionToRun();
	void FunctionNotToRun();
	void FunctionToJump();
	void FunctionNotToJump();

	// Composants

		// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyCamera")
		USpringArmComponent* mySpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyCamera")
		UCameraComponent* myCamera;

public:
	float VSpeed;


};
