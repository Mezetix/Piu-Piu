// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LadicaBase.h"
#include "PartolLadica.generated.h"

/**
 * 
 */
UCLASS()
class PIUPIU_API APartolLadica : public ALadicaBase
{
	GENERATED_BODY()

		UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPoints;
	
	
};
