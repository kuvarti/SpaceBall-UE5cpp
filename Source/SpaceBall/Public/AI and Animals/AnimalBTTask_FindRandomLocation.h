// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AnimalBTTask_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class SPACEBALL_API UAnimalBTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UAnimalBTTask_FindRandomLocation();
	//virtual void OnGameplayTaskActivated(class UGameplayTask&) override;

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownercomp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
		float SearchRadius{ 5000.f };
};
