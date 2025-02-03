// Fill out your copyright notice in the Description page of Project Settings.


#include "MyScriptedActor.h"

// Sets default values
AMyScriptedActor::AMyScriptedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetBoxExtent(FVector(100.0, 100.0, 100.0));
}

void AMyScriptedActor::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!bCanOverlap)
	{
		return;
	}

	auto OtherActorClass= OtherActor->GetClass();
	
	for (auto FilteredActorClass : FilteredActors)
	{
		if (OtherActorClass == FilteredActorClass || FilteredActorClass->IsChildOf(OtherActorClass))
		{
			ActorList.Add(OtherActor);
			GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, "Adding " + OtherActor->GetName());
			break;
		}
	}
}

void AMyScriptedActor::OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ActorList.Contains(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, "Removing " + OtherActor->GetName());
		ActorList.Remove(OtherActor);
	}
}

// Called when the game starts or when spawned
void AMyScriptedActor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AMyScriptedActor::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AMyScriptedActor::OnEndOverlap);
}

void AMyScriptedActor::EnableDamage()
{
	bCanOverlap = true;
	GEngine->AddOnScreenDebugMessage(1, 0.5, FColor::Yellow, "Overlap: On");
	OnDamageBegin();
}

void AMyScriptedActor::DisableDamage()
{
	bCanOverlap = false;
	GEngine->AddOnScreenDebugMessage(1, 0.5, FColor::Yellow, "Overlap: Off");
	OnDamageEnd();
}

// Called every frame
void AMyScriptedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer >= EndTimer)
	{
		Timer = 0;
	}

	Timer += DeltaTime;

	if (Timer > EndTimer * FirstPercentage && Timer < EndTimer * SecondPercentage)
	{
		if (!bCanOverlap)
		{
			EnableDamage();
		}
	}
	else
	{
		if (bCanOverlap)
		{
			DisableDamage();
		}
	}

	// TArray<AActor*> Actors;
	// GetOverlappingActors(Actors, nullptr);

	GEngine->AddOnScreenDebugMessage(2, 0.1, FColor::Blue, "Timer: " + FString::SanitizeFloat(Timer));
}

void AMyScriptedActor::AddActor(AActor* Actor)
{
	if (Actor->IsA(AActor::StaticClass()))
	{
		ActorList.Add(Actor);
	}
}

void AMyScriptedActor::RemoveActor(AActor* Actor)
{
	ActorList.Remove(Actor);
}
