
// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBall/Public/AI and Animals/AnimalBTTask_FindRandomLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UAnimalBTTask_FindRandomLocation::UAnimalBTTask_FindRandomLocation()
{
	NodeName = TEXT("FindRandomLocation");

	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UAnimalBTTask_FindRandomLocation, BlackboardKey));
}

EBTNodeResult::Type UAnimalBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& ownercomp, uint8* NodeMemory)
{ 
	FNavLocation location{};

	AAIController* AIController{ ownercomp.GetAIOwner() };
	const APawn* AIPawn{ AIController->GetPawn() };

	const FVector origin{ AIPawn->GetActorLocation() };

	const UNavigationSystemV1* NavSys{ UNavigationSystemV1::GetCurrent(GetWorld()) };
	if (IsValid(NavSys) && NavSys->GetRandomPointInNavigableRadius(origin, SearchRadius, location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, location.Location);
	}

	FinishLatentTask(ownercomp, EBTNodeResult::Succeeded);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString("Walking Animal(Wolf) Move")); //location.Location.ToString());
	return EBTNodeResult::Succeeded;
}

FString UAnimalBTTask_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector2: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
