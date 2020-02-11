// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPrefabBase.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class PALADINSPROTOTYPE_API AObjectPrefabBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObjectPrefabBase();
	virtual  void SetLifeSpan(float InLifespan) override;
	void SetActive(bool isActive);
	
	FORCEINLINE bool isActive() const { return Active; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float Lifetime = 5;
	FTimerHandle FLifeSpan;
	bool Active;
	void Deactivate();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
