// Copyright Epic Games, Inc. All Rights Reserved.

#include "Programming2GameMode.h"
#include "Programming2Character.h"
#include "UObject/ConstructorHelpers.h"

AProgramming2GameMode::AProgramming2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
