// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBall/Public/Actors/Basket.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "SpaceBall/Public/Actors/Vegetables.h"

// Sets default values
ABasket::ABasket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bCanEverTick = true;
	collision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	collision->InitSphereRadius(100);
	collision->SetCollisionProfileName("collision");
	collision->OnComponentBeginOverlap.AddDynamic(this, &ABasket::OnOverlapBegin);
	collision->OnComponentEndOverlap.AddDynamic(this, &ABasket::OnOverlapEnd);

	RootComponent = collision;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABasket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasket::OnOverlapBegin(UPrimitiveComponent* overlappecomp, AActor* otherActor, UPrimitiveComponent* othercomp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepresult)
{
	if (otherActor->IsA(AVegetables::StaticClass()))
	{
		otherActor->Destroy();
		score += 1;
	}
}

void ABasket::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

