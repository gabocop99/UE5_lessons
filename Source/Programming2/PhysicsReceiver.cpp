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

	Mesh = GetOwner()->GetComponentByClass<UStaticMeshComponent>();
	// ...
}


// Called every frame
void UPhysicsReceiver::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPhysicsReceiver::ReceivePush(float Force, FVector Direction, FVector Location)
{
	FVector ForceVector = Direction * Force * Mesh->GetMass();
	Mesh->SetPhysicsAngularVelocityInDegrees(FVector::Zero());
	Mesh->AddImpulseAtLocation(ForceVector, Location);
	Mesh->SetPhysicsAngularVelocityInDegrees(FVector::Zero());
}

void UPhysicsReceiver::DampPhysics()
{
	auto Velocity = Mesh->GetComponentVelocity();
	auto Angular = Mesh->GetPhysicsAngularVelocityInDegrees();
	FVector DampedVelocity = Velocity * VelocityDampingPercentage;
	FVector DampedAngularVelocity = Angular * VelocityDampingPercentage;
	Mesh->SetPhysicsLinearVelocity(DampedVelocity);
	Mesh->SetPhysicsAngularVelocityInDegrees(DampedAngularVelocity);
}
