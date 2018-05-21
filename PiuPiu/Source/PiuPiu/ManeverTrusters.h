// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ManeverTrusters.generated.h"


class ALadicaBase;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class PIUPIU_API UManeverTrusters : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

public:


	void ManeverTrusters();


	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveUp(float value, UPrimitiveComponent* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveRight(float value, UPrimitiveComponent* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveFront(float value, UPrimitiveComponent* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void PitchUp(float value, UPrimitiveComponent* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void PitchUpAI(float value, APawn* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void RollRight(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void RollRightAI(float value, APawn* Ladica);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void YawRight(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void YawRightAI(float value, APawn* Ladica);

	// force in newtons  - tone * 10
	UPROPERTY(EditDefaultsOnly)
		float MaxSideForce = 5000.0f;
	// SideRotations in  ne vem... Readianih?
	UPROPERTY(EditDefaultsOnly)
		float MaxSideRotation = 30.0f;

	UFUNCTION(BlueprintCallable, Category = "Getter")
		float GetMaxSideRotation();
	
	
};
