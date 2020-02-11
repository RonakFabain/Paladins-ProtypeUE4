// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "ObjectPrefabBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FP_MuzzleLocation = GetOwner()->FindComponentByClass<USceneComponent>();
	if (!FP_MuzzleLocation)
		UE_LOG(LogTemp, Warning, TEXT("Not FOund"));

	


}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::LaunchProjectile()
{
	Aim();
	currentAmmoCount--;
	if (currentAmmoCount <= 0)
	{
		PlayReload();

	}

}

void UWeaponComponent::PlayReload()
{
	currentAmmoCount = magazineAmmoCapacity;
	MAXAmmoCapacity -= magazineAmmoCapacity;
}

void UWeaponComponent::Aim()
{
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{

			const FRotator SpawnRotation = GetOwner()->GetActorForwardVector().Rotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			//World->SpawnActor<ABullet>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		/*	AObjectPrefabBase* PoolableActor = ObjectPooler->GetPooledObject();
			if (PoolableActor == nullptr) {
				UE_LOG(LogTemp, Warning, TEXT("Cannot spawn - object pool drained. "));
				return;
			}
			else
			{
				PoolableActor->SetActorLocation(SpawnLocation);
				PoolableActor->SetLifeSpan(2);
				PoolableActor->SetActive(true);
			}*/
		}
	}
}
