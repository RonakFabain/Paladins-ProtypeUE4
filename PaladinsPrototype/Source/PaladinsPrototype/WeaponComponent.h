// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "ObjectPrefabBase.h"
#include "ObjectPool.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "WeaponComponent.generated.h"

///-A weapon class. This is an actor component class.
//-Each weapon class holds a mesh
//-becomes a child of the player, and then attaches to a socket

UCLASS()
class PALADINSPROTOTYPE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/*UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> ProjectileClass;*/

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AObjectPrefabBase> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USceneComponent* FP_MuzzleLocation = nullptr;



public:

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void LaunchProjectile();
	void PlayReload();
	void Aim();
	

	/*UPROPERTY(EditAnywhere, Category = "Spawner")
		UObjectPool* ObjectPooler;*/

private:


	UPROPERTY(EditAnywhere)
		int MAXAmmoCapacity;
	UPROPERTY(EditAnywhere)
		int magazineAmmoCapacity;
	UPROPERTY(EditAnywhere)
		int currentAmmoCount;
	UPROPERTY(EditAnywhere)
		int rateOfFire;




};
