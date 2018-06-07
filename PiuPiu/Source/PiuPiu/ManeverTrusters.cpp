// Fill out your copyright notice in the Description page of Project Settings.

#include "ManeverTrusters.h"
#include "LadicaBase.h"
#include "Components/PrimitiveComponent.h"


void UManeverTrusters::BeginPlay()
{
	Super::BeginPlay();

	

}



void UManeverTrusters::ManeverTrusters()
{
	// blaah

}

void UManeverTrusters::MoveUp(float value, UPrimitiveComponent* Ladica)
{
	//TODO FIXME
	
//	UE_LOG(LogTemp, Warning, TEXT(" Trusters going up at %f"), value);
	//auto ForceAplied = GetUpVector() * value * MaxSideForce;
	//auto ForceLocation = GetComponentLocation();
	
	//Ladica->AddForce(ForceAplied);
}

void UManeverTrusters::MoveRight(float value, UPrimitiveComponent* Ladica)
{
	
	auto ForceAplied = GetRightVector() * value * MaxSideForce;
	//auto ForceLocation = GetComponentLocation();
	
	Ladica->AddForce(ForceAplied);
}



void UManeverTrusters::MoveFront(float value, UPrimitiveComponent* Ladica)
{

	auto ForceAplied = GetForwardVector() * value * MaxSideForce;
	//auto ForceLocation = GetComponentLocation();
	
	Ladica->AddForce(ForceAplied);
	
}

//	TODO premakni kodo za rotacijo sm... lepši gre... sam bo treba pogruntat neko smoth varanto... da ni tolk robotsko
//void UManeverTrusters::PitchUp(float value, UPrimitiveComponent* Ladica)
//{
//	//UE_LOG(LogTemp, Warning, TEXT(" %s Pitching up at %f"), *(Ladica->GetName()), value);
//	auto PitchAngle = GetComponentRotation();
//	PitchAngle.Add(value*MaxSideRotation* GetWorld()->GetDeltaSeconds(), 0.0f, 0.0f);
//		
//	
//	
//	Ladica->AddLocalRotation(PitchAngle);
//}


void UManeverTrusters::PitchUpAI(float value, APawn* Ladica)
{
	//UE_LOG(LogTemp, Warning, TEXT(" %s  Pitching up at %f"), *(Ladica->GetName()), value);
	FRotator rotation;
	rotation.Pitch = value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	rotation.Yaw = 0.0f;
	rotation.Roll = 0.0f;
	Ladica->AddActorLocalRotation(rotation);

	//UE_LOG(LogTemp, Warning, TEXT("Fwd rot - vect =  %s"), *(rotation.ToString()));
	
}


//void UManeverTrusters::RollRight(float value)
//{
//}
void UManeverTrusters::RollRightAI(float value, APawn* Ladica)
{
	FRotator rotation;

	rotation.Pitch = 0.0f;
	rotation.Yaw = 0.0f;
	rotation.Roll = value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	Ladica->AddActorLocalRotation(rotation);
}
//void UManeverTrusters::YawRight(float value, ALadicaBase* Ladica )
//{
//	FRotator rotation;
//
//	rotation.Pitch = 0.0f;
//	rotation.Yaw = value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
//	rotation.Roll = 0.0f;
//	Ladica->AddActorLocalRotation(rotation);
//}
void UManeverTrusters::YawRightAI(float value, APawn* Ladica)
{
	FRotator rotation;
	
	rotation.Pitch =0.0f;
	rotation.Yaw =  value * MaxSideRotation * GetWorld()->GetDeltaSeconds();
	rotation.Roll = 0.0f;
	Ladica->AddActorLocalRotation(rotation);
	
}

APawn * UManeverTrusters::GetLadicaPawn()
{
	return Cast<APawn>( this->GetAttachmentRoot());
}

float UManeverTrusters::GetMaxSideRotation()
{
	return MaxSideRotation;
}
