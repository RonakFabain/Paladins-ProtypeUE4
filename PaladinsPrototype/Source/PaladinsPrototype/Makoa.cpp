// Fill out your copyright notice in the Description page of Project Settings.


#include "Makoa.h"

AMakoa::AMakoa()
{
	QLifeTime = 2.f;
	FLifeTime = 1.f;
	bCanUseShield = true;
}

void AMakoa::BeginPlay()
{
	Super::BeginPlay();

	
}

void AMakoa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ShieldTimer += DeltaTime;
	if (ShieldTimer >= QLifeTime)
	{
		ShieldTimer = 0;
		bCanUseShield = true;
	}


}

void AMakoa::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FIRE"));
	if (WeaponComponent)
		WeaponComponent->LaunchProjectile();
}

void AMakoa::RMB()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA RMB"));
	RMBRequestFunction();

}

void AMakoa::FAction()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA FAction"));
	if (bCanUseDash)
		FRequestFunction();

}

void AMakoa::QAction()
{
	if (bCanUseShield)
	{
		bCanUseShield = false;


		UE_LOG(LogTemp, Warning, TEXT("MAKOA QAction"));


		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			myShield = World->SpawnActor<AActor>(Shield, GetActorLocation(), GetActorRotation(), SpawnParameters);
			myShield->SetLifeSpan(QLifeTime-1);

		}
	}


}


void AMakoa::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("MAKOA Reload"));


}

void AMakoa::DestroyActor()
{

	//Destroy(myShield);
}

