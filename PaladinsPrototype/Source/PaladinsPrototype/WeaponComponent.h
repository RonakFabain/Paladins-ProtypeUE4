// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "WeaponComponent.generated.h"

///-A weapon class. This is an actor component class.
//-Each weapon class holds a mesh
//-becomes a child of the player, and then attaches to a socket

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> ProjectileClass;

	
		 USceneComponent* FP_MuzzleLocation=nullptr;



public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void LaunchProjectile();
	void PlayReload();
	void Aim();
	void RotatePhysics();

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
