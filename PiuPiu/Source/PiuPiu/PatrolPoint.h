// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPoint.generated.h"

UCLASS()
class PIUPIU_API APatrolPoint : public AActor
{
	GENERATED_BODY()

private:
	




public:	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Sets default values for this actor's properties
	APatrolPoint();
	// construktor za point
	APatrolPoint(FVector lokacija, float blizina = 5000.0f, int hitrost = 100);

	// Lokacija Patol pointa
	UPROPERTY(EditDefaultsOnly, Category = "SetupPatrolPoint")
		FVector Lokacija;

	// Kolk blizi mores pridit da si dosegu tocko
	UPROPERTY(EditDefaultsOnly, Category = "SetupPatrolPoint")
		float BlizinaTarce;

	// A lohk uporablja Fuul Speed - u procentih
	UPROPERTY(EditDefaultsOnly, Category = "SetupPatrolPoint")
		int Hitrost;
	
	//Ime Toèke
	UPROPERTY(EditDefaultsOnly, Category = "SetupPatrolPoint")
		FString Ime;
	
	// Get Lokacija
	UFUNCTION(BlueprintCallable, Category = "GetterPatrolPoint")
		FVector GetLokacija();

	// razdalja ki jo rabis da dosezes tarco - Default 5000
	UFUNCTION(BlueprintCallable, Category = "GetterPatrolPoint")
		float GetBlizinaTarce();
	
	// get Hitrot u procentih
	UFUNCTION(BlueprintCallable, Category = "GetterPatrolPoint")
		int GetHitrost();
	
	// get Ime
	UFUNCTION(BlueprintCallable, Category = "GetterPatrolPoint")
		FString GetIme();


	// Set Lokacija
	UFUNCTION(BlueprintCallable, Category = "SetterPatrolPoint")
		void SetLokacija(FVector loka);

	// razdalja ki jo rabis da dosezes tarco - Default 5000
	UFUNCTION(BlueprintCallable, Category = "SetterPatrolPoint")
		void SetBlizinaTarce(float blizina );

	// set Hitrot u procentih def = 100
	UFUNCTION(BlueprintCallable, Category = "SetterPatrolPoint")
		void SetHitrost(int HitrostProcent);

	// set Hitrot u procentih def = 100
	UFUNCTION(BlueprintCallable, Category = "SetterPatrolPoint")
		void SetIme(FString ime1);



	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	
	
};
