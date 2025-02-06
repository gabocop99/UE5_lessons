// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsReceiver.h"

#include "AssetTypeCategories.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"

// Sets default values for this component's properties
UPhysicsReceiver::UPhysicsReceiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Actor = GetOwner();
	
	// ...
}


// Called when the game starts
void UPhysicsReceiver::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPhysicsReceiver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPhysicsReceiver::ReceivePush(float Force, FVector Direction, FVector Location)
{
	auto Mesh = GetOwner()->GetComponentByClass<UStaticMeshComponent>();
	FVector ForceVector = Direction * Force * Mesh->GetMass();
	Mesh->AddImpulseAtLocation(ForceVector , Location);
}

