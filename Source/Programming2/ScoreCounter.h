// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreCounter.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROGRAMMING2_API UScoreCounter : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UScoreCounter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void AddPoint();

	UPROPERTY()
	int Score = 0;
};
