// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

#include "PhysicsReceiver.h"

// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AGoal::OnBeginOverlap);
}

void AGoal::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	
	if (!IsValid(OtherActor))
	{
		return;
	}

	auto Ball = OtherActor->GetComponentByClass<UPhysicsReceiver>();
	if (IsValid(Ball))
	{
		Score++;
	}
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(4, 0.1, FColor::Red, FString::FromInt(Score));
	
}

