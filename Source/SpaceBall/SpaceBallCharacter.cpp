// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceBallCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

#include "SpaceBall/Public/Actors/Collectable.h"

ASpaceBallCharacter::ASpaceBallCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	bUseControllerRotationYaw = true;
}

void ASpaceBallCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ASpaceBallCharacter::setonHand(class Collectable* c, AActor** a)
{
	if (onHand == nullptr)
	{
		onHand = c;
		*a = this;
	}
}

void ASpaceBallCharacter::usehand()
{
	if (onHand != nullptr)
	{
		onHand->action();
		onHand = nullptr;
	}
}

void ASpaceBallCharacter::GoForward(float value)
{
	if (!value) return;
	FVector loc = GetActorLocation();
	loc.X += value;
	AddMovementInput((loc - GetActorLocation()).GetSafeNormal(), 3, false);
}

void ASpaceBallCharacter::GoSide(float value)
{
	if (!value) return;
	FVector loc = GetActorLocation();
	loc.Y += value;
	AddMovementInput((loc - GetActorLocation()).GetSafeNormal(), 3, false);
}

void ASpaceBallCharacter::beingStunned(float time)
{
	FTimerHandle stuntime;

	GetCharacterMovement()->DisableMovement();
	GetWorldTimerManager().SetTimer(stuntime, this, &ASpaceBallCharacter::reselaseStun, 0.1f, false, time);
}

void ASpaceBallCharacter::reselaseStun()
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}
