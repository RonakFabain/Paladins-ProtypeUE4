// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBase.h"
#include "TimerManager.h"
#include "Makoa.generated.h"

/**
 *
 */


UCLASS()
class PALADINSPROTOTYPE_API AMakoa : public AMyCharacterBase
{
	GENERATED_BODY()


private:

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AActor> Shield;

	AActor* myShield;
	FTimerHandle Duration;
protected:
	AMakoa();
	void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

	void Fire() override;
	void RMB() override;
	void FAction() override;
	void QAction()override;
	void Reload() override;
	void DestroyActor();

public:

	//Events sent to blueprint when ability button is pressed
	UFUNCTION(BlueprintImplementableEvent)
		void FRequestFunction();
	UFUNCTION(BlueprintImplementableEvent)
		void RMBRequestFunction();
	UFUNCTION(BlueprintImplementableEvent)
		void QRequestFunction();

	UPROPERTY(EditAnywhere)
		float	QLifeTime = 0;

	UPROPERTY(EditAnywhere)
		float	FLifeTime = 0;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool bCanUseDash;
};
