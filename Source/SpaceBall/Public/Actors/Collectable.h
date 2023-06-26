// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "string"
/**
 * 
 */
class SPACEBALL_API Collectable
{
public:
	Collectable(class AActor* chr = nullptr, std::string name= "", std::string type = "")
	{
		ownedby = chr;
		_name = name;
		_type = type;
	};
	virtual ~Collectable() { };

	class AActor* getownedby() const { return ownedby; };
	void    setownedby(class AActor* chr) { ownedby = chr; };

	virtual void action() = 0;
protected:
	UPROPERTY()
	std::string	_type;
	UPROPERTY()
	std::string	_name;
	UPROPERTY()
	class AActor* ownedby;
private:
};
