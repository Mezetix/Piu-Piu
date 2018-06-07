// Fill out your copyright notice in the Description page of Project Settings.

#include "ManevertThrust.h"
#include "LadicaBase.h"
#include "Components/StaticMeshComponent.h"



void UManevertThrust::SetupThrusters(ALadicaBase * LadicaBase)
{
	Ladica = LadicaBase;
}

// Sets default values for this component's properties
UManevertThrust::UManevertThrust()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UManevertThrust::SetUpMesh(UStaticMeshComponent * mesh)
{

	LadicaMesh = mesh;

}


// Called when the game starts
void UManevertThrust::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UManevertThrust::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UManevertThrust::MoveUp(float value)
{
	if (!LadicaMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ladica Mesh Manka u %s"), *(Ladica->GetName()));
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = Ladica->GetActorUpVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/
		LadicaMesh->AddForce(ForceAplied);
	}


}

void UManevertThrust::MoveRight(float value)
{
	if (!LadicaMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ladica Mesh Manka u %s"), *(Ladica->GetName()));
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = Ladica->GetActorRightVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
	
		LadicaMesh->AddForce(ForceAplied);
		
	}

}

void UManevertThrust::MoveFront(float value)
{
	if (!LadicaMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ladica Mesh Manka u %s"), *(Ladica->GetName()));
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = Ladica->GetActorForwardVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
		
		LadicaMesh->AddForce(ForceAplied);
		
	}
}

void UManevertThrust::PitchUp(float value)
{



	//Ladica->AddControllerPitchInput(value);


	//UE_LOG(LogTemp, Warning, TEXT(" %s  Pitching up at %f"), *(Ladica->GetName()), value);
	FRotator rotation;
	rotation.Pitch = value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	rotation.Yaw = 0.0f;
	rotation.Roll = 0.0f;
	Ladica->AddActorLocalRotation(rotation);

	//UE_LOG(LogTemp, Warning, TEXT("Fwd rot - vect =  %s"), *(rotation.ToString()));
}
void UManevertThrust::RollRight(float value)
{
	FRotator rotation;
	rotation.Pitch = 0.0f;
	rotation.Yaw = 0.0f;
	rotation.Roll = value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	Ladica->AddActorLocalRotation(rotation);



}
void UManevertThrust::YawRight(float value)
{
	FRotator rotation;

	rotation.Pitch = 0.0f;
	rotation.Yaw =  value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	rotation.Roll =0.0f;
	Ladica->AddActorLocalRotation(rotation);
}