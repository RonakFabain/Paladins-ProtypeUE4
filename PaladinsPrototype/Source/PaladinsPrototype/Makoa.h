// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBase.h"
#include "Makoa.generated.h"

/**
 * 
 */
UCLASS()
class PALADINSPROTOTYPE_API AMakoa : public AMyCharacterBase
{
	GENERATED_BODY()
protected:
	AMakoa();
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void Fire() override;
	void RMB() override;
	void FAction() override;
	void QAction() override;
	void Reload() override;
	
};
