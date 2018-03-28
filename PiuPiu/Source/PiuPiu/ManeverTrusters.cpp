// Fill out your copyright notice in the Description page of Project Settings.

#include "ManeverTrusters.h"
#include "Components/PrimitiveComponent.h"



void UManeverTrusters::MoveUp(float value)
{


//	UE_LOG(LogTemp, Warning, TEXT(" Trusters going up at %f"), value);
	auto ForceAplied = GetUpVector() * value * MaxSideForce;
	auto ForceLocation = GetComponentLocation();
	auto LadicaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	LadicaRoot->AddForceAtLocation(ForceAplied, ForceLocation);
}

void UManeverTrusters::MoveRight(float value)
{
	
	auto ForceAplied = GetRightVector() * value * MaxSideForce;
	auto ForceLocation = GetComponentLocation();
	auto LadicaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	LadicaRoot->AddForceAtLocation(ForceAplied, ForceLocation);

}

void UManeverTrusters::MoveFront(float value)
{

	auto ForceAplied = GetForwardVector() * value * MaxSideForce;
	auto ForceLocation = GetComponentLocation();
	auto LadicaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	LadicaRoot->AddForceAtLocation(ForceAplied, ForceLocation);
	
}

void UManeverTrusters::PitchUp(float value)
{
	//UE_LOG(LogTemp, Warning, TEXT(" Pitching up at %f"), value);
	auto PitchAngle = GetComponentRotation();
	PitchAngle.Add(value*MaxSideRotation, 0.0f, 0.0f);
		
	auto LadicaRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	LadicaRoot->AddLocalRotation(PitchAngle);
}

void UManeverTrusters::RollRight(float value)
{
}

void UManeverTrusters::YawRight(float value)
{
}
