// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceBallGameMode.h"
#include "SpaceBallPlayerController.h"
#include "SpaceBallCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "kayboardContrtoller.h"

ASpaceBallGameMode::ASpaceBallGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AkayboardContrtoller::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/MykeyboardController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}