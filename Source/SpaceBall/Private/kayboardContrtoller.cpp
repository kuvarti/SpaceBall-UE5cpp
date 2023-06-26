// Fill out your copyright notice in the Description page of Project Settings.


#include "kayboardContrtoller.h"
#include "SpaceBall/SpaceBallCharacter.h"
#include "SpaceBall/SpaceBallGameMode.h"

AkayboardContrtoller::AkayboardContrtoller()
{
}

void AkayboardContrtoller::BeginPlay()
{
	Super::BeginPlay();
	Possessedcharacter = Cast<ASpaceBallCharacter>(GetPawn());
	upcontrol = 0;
	sidecontrol = 0;
}

void AkayboardContrtoller::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveUp", this, &AkayboardContrtoller::CallMoveUp);
	InputComponent->BindAxis("MoveDown", this, &AkayboardContrtoller::CallMoveUp);
	InputComponent->BindAxis("MoveRight", this, &AkayboardContrtoller::CallMoveRight);
	InputComponent->BindAxis("MoveLeft", this, &AkayboardContrtoller::CallMoveRight);
	InputComponent->BindAction("Action", IE_Released, this, &AkayboardContrtoller::CallAction);
}

void AkayboardContrtoller::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void	AkayboardContrtoller::CallMoveUp(float value)
{
	upcontrol = value;
	if (value != 0 && Possessedcharacter)
	{
		Possessedcharacter->GoForward(value);
		if (sidecontrol == 0)
		{
			if (value > 0)
				ControlRotation = FRotator(0, 0, 0);
			else
				ControlRotation = FRotator(0, 180, 0);
		}
	}
}

void	AkayboardContrtoller::CallMoveRight(float value)
{
	sidecontrol = value;
	if (value != 0 && Possessedcharacter)
	{
		Possessedcharacter->GoSide(value);
		if (upcontrol == 0)
		{
			if (value > 0)
				ControlRotation = FRotator(0, 90, 0);
			else
				ControlRotation = FRotator(0, 270, 0);
		}
		else if (upcontrol > 0)
		{
			if (value > 0)
				ControlRotation = FRotator(0, 45, 0);
			else
				ControlRotation = FRotator(0, 315, 0);
		}
		else if (upcontrol < 0)
		{
			if (value > 0)
				ControlRotation = FRotator(0, 135, 0);
			else
				ControlRotation = FRotator(0, 225, 0);
		}
	}
}

void AkayboardContrtoller::CallAction()
{
	Possessedcharacter->usehand();
}
