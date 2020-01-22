// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PaladinsPrototypeGameMode.h"
#include "PaladinsPrototypeHUD.h"
#include "PaladinsPrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

APaladinsPrototypeGameMode::APaladinsPrototypeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APaladinsPrototypeHUD::StaticClass();
}
