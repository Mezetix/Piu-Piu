// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ManevertThrust.generated.h"

class ALadicaBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIUPIU_API UManevertThrust : public UActorComponent
{
	GENERATED_BODY()


private:
	ALadicaBase * Ladica = nullptr;
	UStaticMeshComponent* LadicaMesh = nullptr;

	

public:	
	// Sets default values for this component's properties
	UManevertThrust();


	void SetUpMesh(UStaticMeshComponent* mesh);
	

	// force in newtons  - tone * 10 TODO - prevec... skor pol mejn mora bit... 
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxSideForce = 500000000.0f;

	// SideRotations in  ne vem... Readianih?
	UPROPERTY(EditAnywhere, Category="Setup")
		float MaxSideRotation = 30.0f;

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveUp(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveRight(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveFront(float value);


	UFUNCTION(BlueprintCallable, Category = "Movment")
		void PitchUp(float value);
	
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void RollRight(float value);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void YawRight(float value);


// u construktorju doloèmo parent ladjo
	void SetupThrusters(ALadicaBase* LadicaBase);
// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	

		
	
};
