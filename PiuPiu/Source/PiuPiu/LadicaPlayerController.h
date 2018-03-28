// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LadicaPlayerController.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class PIUPIU_API ALadicaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveUp();
	
protected:
	UPROPERTY(EditAnywhere, Category = "Setup") // verjetnu EditDefaultsOnly

		float SideSpeed = 5.0f;
};
