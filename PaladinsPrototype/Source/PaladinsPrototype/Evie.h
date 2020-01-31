// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacterBase.h"
#include "WeaponComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Evie.generated.h"

/**
 *
 */
UCLASS()
class PALADINSPROTOTYPE_API AEvie : public AMyCharacterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* IceBlockMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = " Camera")
		USpringArmComponent* SpringArmComponent;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = " Camera")
		UCameraComponent* TPSCameraComponent;
	
	FORCEINLINE USpringArmComponent* GetSpringArmComponent() const { return SpringArmComponent; }
	FORCEINLINE UCameraComponent* GetTPSCameraComponent() const { return TPSCameraComponent; }

protected:
	AEvie();
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void Fire() override;
	void RMB() override;
	void FAction() override;
	void QAction() override;
	void Reload() override;

private:



	bool bIceBlockState;
	float FTimer;

	void ResetIceBlock();

};
