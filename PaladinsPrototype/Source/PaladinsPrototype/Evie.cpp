// Fill out your copyright notice in the Description page of Project Settings.


#include "Evie.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "GameFramework/SpringArmComponent.h"



AEvie::AEvie()
{
	WeaponComponent = FindComponentByClass<UWeaponComponent>();

	IceBlockMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ice Block"));
	IceBlockMeshComponent->SetupAttachment(RootComponent);
	IceBlockMeshComponent->SetVisibility(false);
	IceBlockMeshComponent->SetComponentTickEnabled(true);
	IceBlockMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bIceBlockState = false;


	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TPSCamera"));
	SpringArmComponent->SetupAttachment(RootComponent);
	TPSCameraComponent->SetupAttachment(SpringArmComponent);
	SpringArmComponent->TargetArmLength = 300;
}
void AEvie::BeginPlay()
{
	Super::BeginPlay();

	ResetIceBlock();
	

}

void AEvie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->GetTimeSeconds() - FTimer > FCoolDown) bIceBlockState = true;



}


void AEvie::Fire()
{

	UE_LOG(LogTemp, Warning, TEXT("AEvie Fire"));
	if (WeaponComponent)
		WeaponComponent->LaunchProjectile();

}

void AEvie::RMB()
{
	FTimerHandle Manager;
	if (bIceBlockState)
	{
		UE_LOG(LogTemp, Warning, TEXT("AEvie RMB"));
		FTimer = GetWorld()->GetTimeSeconds();


		IceBlockMeshComponent->SetVisibility(true);
		IceBlockMeshComponent->SetComponentTickEnabled(true);
		
		IceBlockMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		IceBlockMeshComponent->SetConstraintMode(EDOFMode::Type(bLockLocation));

		WeaponMeshComponent->SetVisibility(false);
		if (SpringArmComponent)
		{
			SpringArmComponent->Activate();
			
		}
	
		if (TPSCameraComponent)
		{
			TPSCameraComponent->Activate();
		}
		if (CameraComponent)
		{
			CameraComponent->Deactivate();
		

		}
		
		

		bIceBlockState = false;

		//wait for time
		GetWorldTimerManager().SetTimer(Manager, this, &AEvie::ResetIceBlock, FCoolDown, false);

	}

}

void AEvie::FAction()
{
	//TpsCamera->EnableTpsCamera();
	//Fly
	//TpsCamera->DisableTpsCamera();
	UE_LOG(LogTemp, Warning, TEXT("AEvie FAction"));
}

void AEvie::QAction()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie QAction"));

	//seek max linetrance on holding q
	//save current position
	//Teleport to line trace end and start timer
	//return back to saved pos on Q pressed or if out of time
	//reset timer
}

void AEvie::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie Reload"));
	if (WeaponComponent)
		WeaponComponent->PlayReload();
}

void AEvie::ResetIceBlock()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie RMB RESET"));
	bIceBlockState = true;

	IceBlockMeshComponent->SetVisibility(false);
	IceBlockMeshComponent->SetComponentTickEnabled(false);
	IceBlockMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	
	WeaponMeshComponent->SetVisibility(true);
	
	if (CameraComponent)
		CameraComponent->Activate();
	if (SpringArmComponent)
		SpringArmComponent->Deactivate();
	if (TPSCameraComponent)
		TPSCameraComponent->Deactivate();
	IceBlockMeshComponent->SetConstraintMode(EDOFMode::None);

	

}
