// Fill out your copyright notice in the Description page of Project Settings.

#include "ManeverTrusters.h"
#include "LadicaBase.h"
#include "Components/PrimitiveComponent.h"


void UManeverTrusters::BeginPlay()
{
	Super::BeginPlay();

	

}



void UManeverTrusters::MoveUp(float value, UPrimitiveComponent* Ladica)
{
	//TODO FIXME
	
//	UE_LOG(LogTemp, Warning, TEXT(" Trusters going up at %f"), value);
	auto ForceAplied = GetUpVector() * value * MaxSideForce;
	//auto ForceLocation = GetComponentLocation();
	
	Ladica->AddForce(ForceAplied);
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
void UManeverTrusters::PitchUp(float value, UPrimitiveComponent* Ladica)
{
	////UE_LOG(LogTemp, Warning, TEXT(" Pitching up at %f"), value);
	//auto PitchAngle = GetComponentRotation();
	//PitchAngle.Add(value*MaxSideRotation, 0.0f, 0.0f);
	//	
	//auto LadicaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//
	//LadicaRoot->AddLocalRotation(PitchAngle);
}

void UManeverTrusters::RollRight(float value)
{
}

void UManeverTrusters::YawRight(float value)
{
}
