// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPrefabBase.h"
#include "TimerManager.h"

// Sets default values
AObjectPrefabBase::AObjectPrefabBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(false);

}

void AObjectPrefabBase::SetLifeSpan(float InLifespan)
{
	Lifetime = InLifespan;
	GetWorldTimerManager().SetTimer(FLifeSpan, this, &AObjectPrefabBase::Deactivate, Lifetime, false);
}

void AObjectPrefabBase::SetActive(bool isActive)
{
	Active = isActive;
	SetActorHiddenInGame(!isActive);
}


void AObjectPrefabBase::Deactivate()
{
	SetActive(false);
}


// Called when the game starts or when spawned
void AObjectPrefabBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectPrefabBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

