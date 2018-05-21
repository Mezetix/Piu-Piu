// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DeffAIController.generated.h"


class ALadicaBase;
/**
 * 
 */
UCLASS()
class PIUPIU_API ADeffAIController : public AAIController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		// Ladico katero AI controlira
		ALadicaBase* GetControledLadica()const;
		
		// Ladico, katero igra igralec
		ALadicaBase* GetPlayerLadja()const;

private:
	ALadicaBase * PlayerLadica = nullptr;
	ALadicaBase*  ControledLadica = nullptr;


};
