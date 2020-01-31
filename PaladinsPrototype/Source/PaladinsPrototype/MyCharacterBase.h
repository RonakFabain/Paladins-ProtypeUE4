// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WeaponComponent.h"
#include "MyCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
UCLASS()
class PALADINSPROTOTYPE_API AMyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBase();


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = " Camera")
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = " Player")
		UStaticMeshComponent* WeaponMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = " Player")
		UWeaponComponent* WeaponComponent = nullptr;

protected:
	// Called when the game starts or when spawned

	void MoveForward(float Val);
	void MoveRight(float Val);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = " Camera")
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = " Camera")
		float BaseLookUpAtRate;

	UPROPERTY(EditAnywhere, Category = "ABILITY COOLDOWNS")
		float FCoolDown;
	UPROPERTY(EditAnywhere, Category = "ABILITY COOLDOWNS")
		float QCoolDown;
	UPROPERTY(EditAnywhere, Category = "ABILITY COOLDOWNS")
		float RMBCoolDown;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TakeDamage(int dmgAmount);
	void Die();


	//Use Interface to implement Actions
	virtual void Fire() PURE_VIRTUAL(AMyCharacterBase::Fire, );
	virtual void RMB() PURE_VIRTUAL(AMyCharacterBase::RMB, );
	virtual void FAction() PURE_VIRTUAL(AMyCharacterBase::FAction, );
	virtual void QAction() PURE_VIRTUAL(AMyCharacterBase::QAction, );
	virtual void Reload() PURE_VIRTUAL(AMyCharacterBase::Reload, );



	FORCEINLINE UCameraComponent* GetCameraComponent() const { return CameraComponent; }


private:

	float currentHealth;
	UPROPERTY(EditAnywhere)
		float MAXHealth;
	UPROPERTY(EditAnywhere)
		float movementSpeed;



};
