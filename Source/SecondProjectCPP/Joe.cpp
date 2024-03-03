// Fill out your copyright notice in the Description page of Project Settings.


#include "Joe.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AJoe::AJoe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*************************
	 * ACCEDER A LA CAPSULE	 *
	 *************************/

	// Radius = GetCapsuleComponent()->SetCapsuleRadius(50.8f);
	// HalftHeight = GetCapsuleComponent()->SetCapsuleHalfHeight(80.f);

	// LES DEUX
	GetCapsuleComponent()->SetCapsuleSize(88.f,88.f);

	/*********************************
	 * ACCEDER A CharactereMovement	 *
	 *********************************/

	// Force du Jump
	// Pour ce personnage : Velocity de 300.f = Hauteur de 46.f environ
	GetCharacterMovement()->JumpZVelocity = 300.f;

	// Controle dans l'air
	GetCharacterMovement()->AirControl = 0.2f;

	// Le personnage tourne en direction de l'INPUT
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Changer la vitesse max de marche
	GetCharacterMovement()->MaxWalkSpeed = 500.f; // de base 600

	/*********************************************************************
	 * On ne veut pas le code/controller gere la rotation mais la cam	 *
	 *********************************************************************/

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	/*****************************
	 * ACCEDER A SkeletalMesh	 *
	 *****************************/

	// Mettre le perso
	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshObj(TEXT("SkeletalMesh'/Game/Acteurs/Joe/Joe.Joe'"));
    if (MeshObj.Object)
    {
    	GetMesh()->SetSkeletalMesh(MeshObj.Object);
    }
    else
    {
	    UE_LOG(LogTemp, Error, TEXT("Erreur Mesh"))
    }

	// Modifier location:Rotation:Scale
	// X - Y - Z
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -80.f));
	// Z(PITCH Tombe devant/arr) - X(Yaw Tourne) - Y(Roll Ce tourne sur lui meme)
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	// Scale
	//GetMesh()->SetWorldScale3D(FVector(1.1f,1.1f,1.1f)); // egal à GetMesh()->SetWorldScale3D(FVector(1.1f));


	/*****************************************
	 * Ajouter un componet : le bras de cam	 *
	 *****************************************/

	mySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("mySpringArm"));

	// Atacher au parent root
	mySpringArm->SetupAttachment(RootComponent);

	// Tourner le bras avec le controller
	mySpringArm->bUsePawnControlRotation = true;

	/*****************************************
	 * Ajouter un componet : la camera   	 *
	 *****************************************/

	myCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera"));

	// Atacher au parent mySpringArm
	myCamera->SetupAttachment(mySpringArm);

	/*****************************************
	 * Donnée la possession de l'acteur   	 *
	 *****************************************/

	AutoPossessPlayer = EAutoReceiveInput::Player0;


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
	TheDeltaTime = DeltaTime;

}

// Called to bind functionality to input
void AJoe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*****************
	 * AXIS Mapping	 *
	 *****************/

	//Perso
	PlayerInputComponent->BindAxis("MoveX", this, &AJoe::FunctionMoveFrontX);
	PlayerInputComponent->BindAxis("MoveY", this, &AJoe::FunctionMoveY);

	//Cam
	PlayerInputComponent->BindAxis("Rotate", this, &AJoe::FunctionRotate);
	PlayerInputComponent->BindAxis("LookUpDown", this, &AJoe::FunctionLookUpDown);

	/*******************
	 * Action Mapping  *
	 *******************/

	PlayerInputComponent->BindAction("ToRun", IE_Pressed,this, &AJoe::FunctionToRun);
	PlayerInputComponent->BindAction("ToRun", IE_Released,this, &AJoe::FunctionNotToRun);

}

void AJoe::FunctionMoveFrontX(float Value)
{
	if (Controller && Value != 0.0f)
	{
		FRotator rotation = Controller->GetControlRotation();
		FRotator YawRotation(0, rotation.Yaw, 0);
		FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, Value);

	}
}

void AJoe::FunctionMoveY(float Value)
{
	if (Controller && Value != 0.0f)
	{
		FRotator rotation = Controller->GetControlRotation();
		FRotator YawRotation(0, rotation.Yaw, 0);
		FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, Value);

	}
}

void AJoe::FunctionRotate(float Value)
{
	// AddControllerYawInput(Value * VitesseHorz * GetWorld()->GetDeltaSeconds());
	AddControllerYawInput(Value * VitesseHorz * TheDeltaTime);
}

void AJoe::FunctionLookUpDown(float Value)
{
	AddControllerPitchInput(Value * VitesseVert * TheDeltaTime);
}

void AJoe::FunctionToRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 900.f;
}

void AJoe::FunctionNotToRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

