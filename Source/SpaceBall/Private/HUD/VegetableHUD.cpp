// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/VegetableHUD.h"
#include "Components/ProgressBar.h"

void UVegetableHUD::NativeConstruct()
{
	Super::NativeConstruct();
	SetVisibility(ESlateVisibility::Hidden);
}

void UVegetableHUD::setbar(float current, float max=1)
{
	if (prgsbar)
	{
		SetVisibility(ESlateVisibility::Visible);
		prgsbar->SetPercent(max - current);
	}
	if (current == 0)
		SetVisibility(ESlateVisibility::Hidden);
}
