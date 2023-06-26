// Fill  out your copyright notice in the Description page of Project Settings.

#include "SpaceBall/Public/Actors/CollectableActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SpaceBall/Public/HUD/VegetableHUD.h"
#include "Blueprint/UserWidget.h"
#include "../SpaceBallCharacter.h"
#include "GameFramework/Controller.h"
#include "SpaceBall/SpaceBallPlayerController.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACollectableActor::ACollectableActor(float cScale)
{
	cScale = 10.0f;
	collectTime = 1.0f;

	PrimaryActorTick.bCanEverTick = true;
	collision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	collision->InitSphereRadius(cScale);
	collision->SetCollisionProfileName("collision");
	collision->OnComponentBeginOverlap.AddDynamic(this, &ACollectableActor::OnOverlapBegin);
	collision->OnComponentEndOverlap.AddDynamic(this, &ACollectableActor::OnOverlapEnd);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = mesh;
	collision->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ACollectableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectableActor::OnOverlapBegin(UPrimitiveComponent* overlappecomp, AActor* otherActor, UPrimitiveComponent* othercomp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepresult)
{
	if (ownedby != nullptr && !Cast<ACharacter>(otherActor))
		return;
	if (GetWorldTimerManager().TimerExists(cTimerHandle))
		GetWorldTimerManager().UnPauseTimer(cTimerHandle);
	else
		GetWorldTimerManager().SetTimer(cTimerHandle, this, &ACollectableActor::TimerFunction, 0.1f, false, collectTime);
}

void ACollectableActor::OnOverlapEnd(UPrimitiveComponent* overlappecomp, AActor* otherActor, UPrimitiveComponent* othercomp, int32 otherBodyIndex)
{
	if (ownedby != nullptr)
		return;
	GetWorldTimerManager().PauseTimer(cTimerHandle);
}

void ACollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->ownedby != nullptr)
	{
		this->SetActorLocation(ownedby->GetActorLocation() + FVector(0, 0, 100.0f));
	}
}

void ACollectableActor::action() { }

void ACollectableActor::TimerFunction()
{
	TSet<AActor *> over;
	collision->GetOverlappingActors(over, ASpaceBallCharacter::StaticClass());
	for (auto it: over)
	{
		if (it->IsA(ASpaceBallCharacter::StaticClass()))
			Cast<ASpaceBallCharacter>(it)->setonHand(this, &ownedby);
		break;
	}
	if (ownedby != nullptr)
		GetWorldTimerManager().ClearTimer(cTimerHandle);
}