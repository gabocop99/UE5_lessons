// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomTPCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACustomTPCharacter::ACustomTPCharacter()
{
	// Inizializza i componenti	
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->SetCrouchedHalfHeight(52.0f);

	// Crea e imposta il Spring Arm (per la telecamera)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ScriptedSpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f; // Distanza della telecamera dal personaggio
	SpringArm->bUsePawnControlRotation = true; // Permette alla telecamera di ruotare con il personaggio

	// Crea e imposta la telecamera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ScriptedCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // La telecamera non ruota con il mouse (è fissa)

	// Imposta il pawn per il movimento
	AutoPossessPlayer = EAutoReceiveInput::Player0; // Imposta il personaggio come controllato dal primo giocatore

	// Imposta la mesh predefinita (devi averla già aggiunta al progetto)
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Path/To/Your/CharacterMesh.CharacterMesh'"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ACustomTPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACustomTPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACustomTPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACustomTPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACustomTPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ACustomTPCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACustomTPCharacter::LookUp);
}

void ACustomTPCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACustomTPCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ACustomTPCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ACustomTPCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}