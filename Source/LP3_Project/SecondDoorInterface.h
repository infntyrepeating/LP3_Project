// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SecondDoorInterface.generated.h"

/**
 * 
 */

UINTERFACE(MinimalAPI)
class USecondDoorInterface : public UInterface
{
	GENERATED_BODY()
};

class LP3_PROJECT_API ISecondDoorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnInteractCPP();
};
