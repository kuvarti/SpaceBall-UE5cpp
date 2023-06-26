// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableActor.h"
#include "GameFramework/Actor.h"
#include "Vegetables.generated.h"

/**
 * 
 */
UCLASS()
class SPACEBALL_API AVegetables : public ACollectableActor
{
	GENERATED_BODY()
public:
	AVegetables(): ACollectableActor(10.0f)
	{
		PrimaryActorTick.bCanEverTick = true;
	};

	virtual void action() override;
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float	yawrotate;
	void afterthrow();
private:
	FRotator rotate;
};