// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBall/Public/AI and Animals/AnimalAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAnimalAIController::AAnimalAIController()
{
	behaviortreecomp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("behaviortreecomp"));
	blackboardcomp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("blackboardcomp"));
}

void AAnimalAIController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(behaviortree.Get()))
	{
		RunBehaviorTree(behaviortree.Get());
		behaviortreecomp->StartTree(*behaviortree.Get());
	}
}

void AAnimalAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	if (IsValid(Blackboard.Get()) && IsValid(behaviortree.Get()))
	{
		Blackboard->InitializeBlackboard(*behaviortree->BlackboardAsset.Get());
	}
}
