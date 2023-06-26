 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "GameFramework/Actor.h"
#include "HUD/VegetableHUD.h"
#include "UObject/Object.h"
#include "CollectableActor.generated.h"

UCLASS()
class SPACEBALL_API ACollectableActor: public AActor, public Collectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableActor() { } ;
	ACollectableActor(float);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(UPrimitiveComponent* overlappecomp, AActor* otherActor, UPrimitiveComponent* othercomp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepresult);
	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USphereComponent* collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* mesh;

	UPROPERTY(BlueprintReadWrite, Category = Time)
		float collectTime;

	UPROPERTY(BlueprintReadWrite, Category = Time)
	FTimerHandle cTimerHandle;
	void	TimerFunction();
public:
	// Called every frame
	virtual void Tick(float DeltaTime);

	UFUNCTION()
	virtual void action() override;
};
