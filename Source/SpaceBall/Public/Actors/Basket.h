// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Basket.generated.h"

UCLASS()
class SPACEBALL_API ABasket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int score;

	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(UPrimitiveComponent* overlappecomp, AActor* otherActor, UPrimitiveComponent* othercomp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepresult);
	UFUNCTION(BlueprintCallable)
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* mesh;

};
