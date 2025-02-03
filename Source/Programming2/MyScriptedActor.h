// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MyScriptedActor.generated.h"

UCLASS()
class PROGRAMMING2_API AMyScriptedActor : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void EnableDamage();

	UFUNCTION()
	void DisableDamage();
	
	UPROPERTY()
	bool bCanOverlap = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float EndTimer = 10;
	
	UPROPERTY()
	float Timer = 0;
	
	UPROPERTY()
	float FirstPercentage = 0.2;
	
	UPROPERTY()
	float SecondPercentage = 0.8;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageEnd();

public:
	AMyScriptedActor();
	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AActor>> FilteredActors;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> ActorList;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void AddActor(AActor* Actor);
	
	UFUNCTION(BlueprintCallable)
	void RemoveActor(AActor* Actor);
	
	//if overlapped object is contained in ActorList, make raise Custom Event

	//Conventions
	int Variable = 0;
	bool bIsRunning = false;
};
