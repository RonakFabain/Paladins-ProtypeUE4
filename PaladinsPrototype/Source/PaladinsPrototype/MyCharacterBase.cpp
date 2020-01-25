// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"


// Sets default values

AMyCharacterBase::AMyCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	CameraComponent->bUsePawnControlRotation = true;



	WeaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComponent"));
	WeaponMeshComponent->SetupAttachment(CameraComponent);

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("Weapon Component"));
	
	BaseLookUpAtRate = 45;
	BaseTurnRate = 45;
}

void AMyCharacterBase::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);

}

void AMyCharacterBase::MoveRight(float Value)
{

	AddMovementInput(GetActorRightVector(), Value);

}



// Called every frame
void AMyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacterBase::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacterBase::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacterBase::MoveRight);

	bUseControllerRotationPitch = true;
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	///Binding different actions
	
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacterBase::Fire);
	PlayerInputComponent->BindAction("RMB", IE_Pressed, this, &AMyCharacterBase::RMB);
	PlayerInputComponent->BindAction("Q", IE_Pressed, this, &AMyCharacterBase::QAction);
	PlayerInputComponent->BindAction("F", IE_Pressed, this, &AMyCharacterBase::FAction);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyCharacterBase::Reload);
	//T to spray?
	
}

void AMyCharacterBase::TakeDamage(int dmgAmount)
{
	currentHealth -= dmgAmount;
	if (currentHealth <= 0)
		Die();
}

void AMyCharacterBase::Die()
{
	//idk
	//call ui
}

