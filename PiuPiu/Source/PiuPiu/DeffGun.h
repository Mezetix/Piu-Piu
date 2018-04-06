// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "DeffGun.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class PIUPIU_API UDeffGun : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	
	
};
