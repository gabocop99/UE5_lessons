// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMING2_API ACustomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ACustomGameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	TSubclassOf<APawn> MyDefaultPawnClass;
};
