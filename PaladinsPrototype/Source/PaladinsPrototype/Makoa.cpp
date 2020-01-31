// Fill out your copyright notice in the Description page of Project Settings.


#include "Makoa.h"

AMakoa::AMakoa()
{

}

void AMakoa::BeginPlay()
{
	Super::BeginPlay();

}

void AMakoa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMakoa::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));
	if (WeaponComponent)
		WeaponComponent->LaunchProjectile();
}

void AMakoa::RMB()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));

}

void AMakoa::FAction()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));

}

void AMakoa::QAction()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));

}

void AMakoa::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));

}
