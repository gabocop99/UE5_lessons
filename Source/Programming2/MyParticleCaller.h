// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Programming2Character.h"
#include "Components/ActorComponent.h"
#include "MyParticleCaller.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROGRAMMING2_API UMyParticleCaller : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	AProgramming2Character* Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleCollision", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleCollision", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ChoosenParticle = nullptr;

	UPROPERTY()
	UActorComponent* MyParticleCallerComponent;

public:
	// Sets default values for this component's properties
	UMyParticleCaller();
	UFUNCTION(BlueprintCallable)
	void SpawnParticleOnHit(FVector SpawnPosition);
	UFUNCTION()
	void OnHitBall(FHitResult Hit);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
