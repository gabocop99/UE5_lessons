// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersManager.h"

// Sets default values
APlayersManager::APlayersManager(): Player1(nullptr), Player2(nullptr)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void APlayersManager::SetPlayer1(AProgramming2Character* PlayerToAdd)
{
	Player1 = PlayerToAdd;
}

void APlayersManager::SetPlayer2(AProgramming2Character* PlayerToAdd)
{
	Player2 = PlayerToAdd;
}

AProgramming2Character* APlayersManager::GetPlayer1()
{
	return Player1;
}

AProgramming2Character* APlayersManager::GetPlayer2()
{
	return Player1;
}

// Called when the game starts or when spawned
void APlayersManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayersManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
