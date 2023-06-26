// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "kayboardContrtoller.generated.h"

/**
 * 
 */
UCLASS()
class SPACEBALL_API AkayboardContrtoller : public APlayerController
{
	GENERATED_BODY()
public:
	AkayboardContrtoller();

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
		void	CallMoveUp(float value);

	UFUNCTION(BlueprintCallable)
		void	CallMoveRight(float value);

	UFUNCTION(BlueprintCallable)
		void	UseObject(float value) {};

	UFUNCTION(BlueprintCallable)
	void CallAction();

	float upcontrol;
	float sidecontrol;

	class ASpaceBallCharacter* Possessedcharacter;
};
