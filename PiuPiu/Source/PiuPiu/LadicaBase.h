// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LadicaBase.generated.h"

class UDeffGun;
class AProjectile;
class UManeverTrusters;
class UManevertThrust;
class APatrolPoint;

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


	//Za turning trusterje

	USceneComponent* FrontPoint;
	USceneComponent* BackPoint;
	USceneComponent* LeftPoint;
	USceneComponent* RightPoint;


	// za AI za obracat
	UManeverTrusters* ManeverThrusters = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxThrustersForce = 50000000.0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ThrustersStep = 5000000.0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float CurrentThrust = 0.0f;


	// Za obraèanje u AI
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 20;
	
	// force in newtons  - tone * 10 TODO - prevec... skor pol mejn mora bit... 
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxSideForce = 50000000.0f;

	UStaticMeshComponent* LadicaMesh;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UManevertThrust* LadicaManeverThrustComponent = nullptr;
	

	// Must call in constructor
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetupGuns(UDeffGun* GunLeft, UDeffGun* GunRight);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetupLadica(UStaticMeshComponent* ladica);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetupManeverThrusters(UManeverTrusters* ManeverThrust);

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ALadicaBase* GetLadica() { return this; }

	// tarca od AI
	FVector Tarca;
	// Kam morem it da pridem do tarèe - local - AI
	FVector Heading;
	// rotator do tarèe
	FRotator RotToTarget;
	// AI command ime
	FString CommandName;
	// AI razdalja do tarèe
	float DistToTarget;

	TArray<APatrolPoint*> PatrolPoints;

	APatrolPoint*	ActivePatrolPoint;

	// Movment funkcije

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveUpBase(float value);

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveRightBase(float value);
	
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MoveFrontBase(float value);


	// n vem  TODO zbris èe se ne uporabla
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void PitchUpBase(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void YawRightBase(float value);
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void RollRightBase(float value);


	UFUNCTION(BlueprintCallable, Category = "Movment")
		void MojTick();


	// MAinThrust Funkcija
	UFUNCTION(BlueprintCallable, Category = "Movment")
		void Thrust();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustMax();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustStop();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustUpStep();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void ThrustDownStep();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		float GetCurrentThrust();
	UFUNCTION(BlueprintCallable, Category = "Movment")
		float GetMaxThrust();

	UFUNCTION(BlueprintCallable, Category = "Movment")
		void SetThrust(float Value);


	// **** AI ****
	UFUNCTION(BlueprintCallable, Category = "AI")
		FVector GetTarca();
	UFUNCTION(BlueprintCallable, Category = "AI")
		FVector GetHeading();
	UFUNCTION(BlueprintCallable, Category = "AI")
		FRotator GetRotToTarget();
	UFUNCTION(BlueprintCallable, Category = "AI")
		FString GetCommandName();
	UFUNCTION(BlueprintCallable, Category = "AI")
		float GetDistToTarget();


	//Next Patrol Point
	UFUNCTION(BlueprintCallable, Category = "PatrolPoint")
		void NaslednjiPatrolPoint();

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
		TSubclassOf<APatrolPoint> PatrolPointBlueprint;



	


	UPROPERTY(EditAnywhere, Category = "Setup")
		float ProjectileSpeed = 1000.0f;

	// Vrne rotacijo ki je potrebna od Foward vektorja proti tarèi (World Coordinate)
	FRotator AngleToward(FVector tarca);
	
};
