// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();

	if (PooledObjectSubclass != NULL)
	{
		/* Check for a valid World */
		UWorld* const World = GetWorld();
		if (World) {
			/* Spawn objects, make them 'inactive' and add them to pool */
			for (int i = 0; i < PoolSize; i++) {
				AObjectPrefabBase* PoolableActor = World->SpawnActor<AObjectPrefabBase>(PooledObjectSubclass, FVector().ZeroVector, FRotator().ZeroRotator);
				PoolableActor->SetActive(false);
				Pool.Add(PoolableActor);
			}
		}
	}
	
}

AObjectPrefabBase* UObjectPool::GetPooledObject()
{
	for (AObjectPrefabBase* PoolableActor : Pool)
	{
		if (!PoolableActor->isActive()) {
			return PoolableActor;
		}
	}
	/* pool is drained, no inactive objects found */
	return nullptr;
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

