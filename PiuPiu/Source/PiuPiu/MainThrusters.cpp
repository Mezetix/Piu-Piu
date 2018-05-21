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


}

void UMainThrusters::ThrustStop(UPrimitiveComponent * Ladica)
{

	CurrentThrust = 0.0f;
	

}

void UMainThrusters::ThrustUpStep(UPrimitiveComponent * Ladica)
{

	CurrentThrust = CurrentThrust  + ThrustersStep;
	if (CurrentThrust > MaxThrustersForce)
	{
		CurrentThrust = MaxThrustersForce;
	}

	

}

void UMainThrusters::ThrustDownStep(UPrimitiveComponent * Ladica)
{
	CurrentThrust = CurrentThrust - ThrustersStep;
	if (CurrentThrust < 0.0f)
	{
		CurrentThrust = 0.0f;
	}
	
	

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

