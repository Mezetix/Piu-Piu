// Fill out your copyright notice in the Description page of Project Settings.

#include "LadicaPlayerController.h"
#include "LadicaBase.h"


void ALadicaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControledLadica = GetControledLadica();
	UE_LOG(LogTemp, Warning, TEXT(" LAdica possest by PlayerControler %s"), *(ControledLadica->GetName()));

}

void ALadicaPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowordsCrosshair();

}

ALadicaBase * ALadicaPlayerController::GetControledLadica()const
{
	return Cast<ALadicaBase>(GetPawn());
}

void ALadicaPlayerController::AimTowordsCrosshair() 
{
	if (!GetControledLadica()) { return; }



}
