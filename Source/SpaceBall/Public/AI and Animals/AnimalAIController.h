// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AnimalAIController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEBALL_API AAnimalAIController : public AAIController
{
	GENERATED_BODY()
public:
	AAnimalAIController();
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn * pawn) override;
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<UBehaviorTree> behaviortree;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<class UBehaviorTreeComponent> behaviortreecomp;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<UBlackboardComponent> blackboardcomp;
};
