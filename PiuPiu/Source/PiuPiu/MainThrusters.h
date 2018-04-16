// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MainThrusters.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIUPIU_API UMainThrusters : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMainThrusters();


	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustMax(UPrimitiveComponent* Ladica);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustStop(UPrimitiveComponent* Ladica);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustUpStep(UPrimitiveComponent* Ladica);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustDownStep(UPrimitiveComponent* Ladica);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		float GetCurrentThrust();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxThrustersForce = 50000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ThrustersStep = 5000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float CurrentThrust = 0.0f;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
private:




};
