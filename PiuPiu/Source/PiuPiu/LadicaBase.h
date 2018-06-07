// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LadicaBase.generated.h"

class UDeffGun;
class AProjectile;
class UManeverTrusters;
class UManevertThrust;
class UMainThrusters;

UCLASS()
class PIUPIU_API ALadicaBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALadicaBase();


private:


	bool setup = false;

	//Local reference of the guns - rabmo za strelanje
	UDeffGun * DefGunLeft = nullptr;
	UDeffGun * DefGunRight = nullptr;


	// za AI za obracat
	UManeverTrusters* ManeverThrusters = nullptr;

	// Za obraèanje u AI
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 20;
	

	UStaticMeshComponent* LadicaMesh;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UManevertThrust* LadicaManeverThrustComponent = nullptr;
	UMainThrusters* LadicaMainThrusters = nullptr;

	// Must call in constructor
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetupGuns(UDeffGun* GunLeft, UDeffGun* GunRight);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetupLadica(UStaticMeshComponent* ladica);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetupManeverThrusters(UManeverTrusters* ManeverThrust);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ALadicaBase* GetLadica() { return this; }

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveUpBase(float value);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveRightBase(float value);
	
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveFrontBase(float value);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void PitchUpBase(float value);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MojTick();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

	void TurnTowards(FVector TurnDirection);

	// vrne MeshComponent od ladice
	UStaticMeshComponent* GetLadicaMesh();

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void Yaw(float value);

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float ProjectileSpeed = 1000.0f;
	
};
