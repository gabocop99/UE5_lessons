// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values
UHealthComponent::UHealthComponent()
{
	// Set this actor to call
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 1.0f;
}

// Called when the game starts or when spawned
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Current Health: " + FString::FromInt(CurrentHealth));

	OnDamageTaken.AddDynamic(this, &UHealthComponent::ResetHealTimer);
}

void UHealthComponent::GetDamageInEditor()
{
	GetDamage();
}

void UHealthComponent::GetDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	OnDamageTaken.Broadcast();
	OnHealthChanged.Broadcast();
}

void UHealthComponent::HealInEditor()
{
	Heal();
}

void UHealthComponent::Heal(float HealAmount)
{
	OnHealthChanged.Broadcast();
	if (CurrentHealth + HealAmount > MaxHealth)
	{
		CurrentHealth = MaxHealth;
		return;
	}
	CurrentHealth += HealAmount;
}

void UHealthComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bCanAutoRecover)
	{
		return;
	}

	HealingTimer += DeltaTime;

	if (HealingTimer >= WaitTimeToStartRecover)
	{
		HealOverTime();
	}
}

void UHealthComponent::HealOverTime()
{
	Heal(AmountToRecoverPerSecond);
}

void UHealthComponent::ResetHealTimer()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Resetting heal timer");
	HealingTimer = 0;
}

float UHealthComponent::GetHealthPercentage()
{
	return CurrentHealth / MaxHealth;
}
