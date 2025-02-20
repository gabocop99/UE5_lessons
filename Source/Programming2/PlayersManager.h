// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Programming2Character.h"
#include "GameFramework/Actor.h"
#include "PlayersManager.generated.h"

UCLASS()
class PROGRAMMING2_API APlayersManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayersManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AProgramming2Character* Player1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AProgramming2Character* Player2;

	UFUNCTION(BlueprintCallable)
	void SetPlayer1(AProgramming2Character* PlayerToAdd);

	UFUNCTION(BlueprintCallable)
	void SetPlayer2(AProgramming2Character* PlayerToAdd);

	UFUNCTION(BlueprintCallable)
	AProgramming2Character* GetPlayer1();

	UFUNCTION(BlueprintCallable)
	AProgramming2Character* GetPlayer2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
