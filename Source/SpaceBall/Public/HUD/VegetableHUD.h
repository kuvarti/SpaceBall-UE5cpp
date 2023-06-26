// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VegetableHUD.generated.h"

/**
 * 
 */
UCLASS()
class SPACEBALL_API UVegetableHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UFUNCTION(BlueprintCallable)
	void	setbar(float current, float max);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* prgsbar;
};
