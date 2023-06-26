// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceBallCharacter.generated.h"

UCLASS(Blueprintable)
class ASpaceBallCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpaceBallCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	// getter - setter hand
	void	setonHand(class Collectable* c, class AActor** a);

	void usehand();

	void	GoForward(float value);
	void	GoSide(float value);

	class Collectable*	onHand;

	UFUNCTION(BlueprintCallable)
	void	beingStunned(float time);

	UFUNCTION()
	void	reselaseStun();
private:

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

