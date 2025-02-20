// Fill out your copyright notice in the Description page of Project Settings.


#include "MyParticleCaller.h"

#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "ProfilingDebugging/CookStats.h"

// Sets default values for this component's properties
UMyParticleCaller::UMyParticleCaller()
{

	PrimaryComponentTick.bCanEverTick = true;
		FString particleEffectPath = "/Game/StarterContent/Particles/P_Explosion.P_Explosion";
		ChoosenParticle = Cast<
			UParticleSystem>(StaticLoadObject(UParticleSystem::StaticClass(), NULL, *particleEffectPath));
	MyParticleCallerComponent = CreateDefaultSubobject<UActorComponent>(TEXT("ParticleCaller"));
}
void UMyParticleCaller::SpawnParticleOnHit(FVector Position)
{
	//Inserire qua veedback colpo, se bHit è la ball, play fsx, camera shake
	// play effect
	ParticleComponent = UGameplayStatics::SpawnEmitterAtLocation(this, ChoosenParticle, Position,FRotator::ZeroRotator);
}


void UMyParticleCaller::OnHitBall(FHitResult Hit)
{
	SpawnParticleOnHit(Hit.Location);
}

// Called when the game starts
void UMyParticleCaller::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AProgramming2Character::StaticClass(), OutActors);

	for (AActor* Actor : OutActors)
	{
		if (IsValid(Actor))
		{
			auto Player = Cast<AProgramming2Character>(Actor);
			if (IsValid(Player))
			{
				Player->OnShootHit.AddDynamic(this, &UMyParticleCaller::OnHitBall);
			}
		}
	}
	

}


// Called every frame
void UMyParticleCaller::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

