// Fill out your copyright notice in the Description page of Project Settings.


#include "Evie.h"


AEvie::AEvie()
{
	//Super::WeaponComponent =GetOwner()->FindComponentByClass()
	//WeaponComponent = GetOwner()->FindComponentByClass<UWeaponComponent>();
}
void AEvie::BeginPlay()
{
	Super::BeginPlay();

}

void AEvie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
///-A weapon class. This is an actor class.
//-Each weapon class holds a mesh
//-becomes a child of the player, and then attaches to a socket

void AEvie::Fire() 
{
	
	UE_LOG(LogTemp, Warning, TEXT("AEvie Fire"));
	if (WeaponComponent)
		WeaponComponent->LaunchProjectile();
	

}

void AEvie::RMB()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie RMB"));
}

void AEvie::FAction()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie FAction"));
}

void AEvie::QAction()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie QAction"));
}

void AEvie::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("AEvie Reload"));
}
