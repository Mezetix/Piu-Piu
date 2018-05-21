// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LadicaBase.generated.h"

class UDeffGun;
class AProjectile;
class UManeverTrusters;

UCLASS()
class PIUPIU_API ALadicaBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALadicaBase();


private:

	//Local reference of the guns - rabmo za strelanje
	UDeffGun * DefGunLeft = nullptr;
	UDeffGun * DefGunRight = nullptr;


	// za AI za obracat
	UManeverTrusters* ManeverThrusters = nullptr;

	// Za obraèanje u AI
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 20;
	

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Must call in constructor
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetupGuns(UDeffGun* GunLeft, UDeffGun* GunRight);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetupManeverThrusters(UManeverTrusters* ManeverThrust);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ALadicaBase* GetLadica() { return this; }


	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

	void TurnTowards(FVector TurnDirection);


	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float ProjectileSpeed = 1000.0f;
	
};
