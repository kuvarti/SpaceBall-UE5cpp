// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceBall/Public/Actors/Vegetables.h"

void AVegetables::action()
{
	FTimerHandle tTimerHandle;

	mesh->SetSimulatePhysics(true);
	mesh->AddForce(ownedby->GetActorForwardVector() * 100000 * mesh->GetMass());
	GetWorldTimerManager().SetTimer(tTimerHandle, this, &AVegetables::afterthrow, 0.1f, false, 1.f);

	ownedby = nullptr;
}

void AVegetables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	rotate = FRotator(0, yawrotate, 0);
	
	FQuat QuatRotation = FQuat(rotate);
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

void AVegetables::afterthrow()
{
	mesh->SetSimulatePhysics(false);

	SetActorLocation(mesh->GetRelativeLocation());
	FVector newloc= GetActorLocation();
	SetActorLocation(newloc + FVector(0, 100.f, 0));

	mesh->SetWorldRotation(FQuat(FRotator(0, 0, 0)));
	mesh->SetWorldLocation(GetActorLocation());

	FQuat QuatRotation = FQuat(FRotator(0, 0, 0));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}
