// Fill out your copyright notice in the Description page of Project Settings.

#include "MainThrusters.h"


// Sets default values for this component's properties
UMainThrusters::UMainThrusters()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UMainThrusters::ThrustMax(UPrimitiveComponent * Ladica)
{
	
	CurrentThrust = MaxThrustersForce;

	UE_LOG(LogTemp, Warning, TEXT(" Thrustin forward at Max"));
}

void UMainThrusters::ThrustStop(UPrimitiveComponent * Ladica)
{

	CurrentThrust = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT(" Thrustin set to stop"));

}

void UMainThrusters::ThrustUpStep(UPrimitiveComponent * Ladica)
{

	CurrentThrust = CurrentThrust  + ThrustersStep;
	if (CurrentThrust > MaxThrustersForce)
	{
		CurrentThrust = MaxThrustersForce;
	}

	UE_LOG(LogTemp, Warning, TEXT(" Thrust up a step... Thrust at %f"), CurrentThrust);

}

void UMainThrusters::ThrustDownStep(UPrimitiveComponent * Ladica)
{
	CurrentThrust = CurrentThrust - ThrustersStep;
	if (CurrentThrust < 0.0f)
	{
		CurrentThrust = 0.0f;
	}
	
	UE_LOG(LogTemp, Warning, TEXT(" Thrust down a step... Thrust at %f"), CurrentThrust);

}

float UMainThrusters::GetCurrentThrust()
{
	return CurrentThrust;
}

// Called when the game starts
void UMainThrusters::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMainThrusters::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

