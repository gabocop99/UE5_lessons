// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthStateChange);

UCLASS()
class PROGRAMMING2_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float CurrentHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool bCanAutoRecover = true;

	UPROPERTY(EditAnywhere, Category = "Health")
	float AmountToRecoverPerSecond = 1;

	UPROPERTY(EditAnywhere, Category = "Health")
	float WaitTimeToStartRecover = 25;

	UPROPERTY(BlueprintAssignable)
	FHealthStateChange OnDamageTaken;

	UPROPERTY(BlueprintAssignable)
	FHealthStateChange OnDeath;

	UPROPERTY(BlueprintAssignable)
	FHealthStateChange OnHealthChanged;

	UPROPERTY()
	float HealingTimer = 0;

public:
	// Sets default values for this actor's properties
	UHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(CallInEditor)
	void GetDamageInEditor();
	
	UFUNCTION(BlueprintCallable)
	void GetDamage(float DamageAmount = 1);

	UFUNCTION(CallInEditor)
	void HealInEditor();
	
	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount = 1);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void HealOverTime();

	UFUNCTION()
	void ResetHealTimer();

	UFUNCTION(BlueprintCallable)
	float GetHealthPercentage();
};
