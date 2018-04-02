// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LadicaPlayerController.generated.h"


class ALadicaBase;
/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class PIUPIU_API ALadicaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 

	
	
protected:



	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	ALadicaBase* GetControledLadica()const;

	UPROPERTY(EditAnywhere, Category = "Setup") // verjetnu EditDefaultsOnly
		float SideSpeed = 5.0f;

private:
	// raycast skozi piko na zaslovu u svet - in kaj trofne... vsak tick
	void AimTowordsCrosshair();

};
