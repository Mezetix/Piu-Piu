// Fill out your copyright notice in the Description page of Project Settings.

#include "MainThrusters.h"
#include "LadicaBase.h"
#include "Components/StaticMeshComponent.h"

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

void UMainThrusters::Thrust()
{
	if (!(Ladica->GetLadicaMesh()))
	{
		UE_LOG(LogTemp, Warning, TEXT(" Ladica->GetLadicaMesh() = null"), *(this->GetName()));
		return;
	}
	auto LadicaMesh = Ladica->GetLadicaMesh();
	if (!LadicaMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT(" LadicaMesh je null MainThrusters"), *(this->GetName()));
		return;
	}
	


	if (CurrentThrust > 0)
	{
		FVector fowVec = LadicaMesh->GetForwardVector();
		FVector FotceToAdd = fowVec * CurrentThrust  * GetWorld()->GetDeltaSeconds();

		LadicaMesh->AddForce(FotceToAdd);
	}

}

// Called when the game starts
void UMainThrusters::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMainThrusters::SetupMainThrusters(ALadicaBase * LadicaBase)
{

	Ladica = LadicaBase;


}


// Called every frame
void UMainThrusters::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

