// Fill out your copyright notice in the Description page of Project Settings.

#include "DeffAIController.h"
#include "LadicaBase.h"


void ADeffAIController::BeginPlay()
{
	Super::BeginPlay();

	ControledLadica = GetControledLadica();
	PlayerLadica = GetPlayerLadja();

	if(!PlayerLadica & !ControledLadica)
	{
		UE_LOG(LogTemp, Warning, TEXT(" Ladica ni našla nè... error"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" Ladica %s nasla igralca %s"), *(ControledLadica->GetName()), *(PlayerLadica->GetName()));
	}

	
	
}

void ADeffAIController::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

}

ALadicaBase * ADeffAIController::GetControledLadica()const
{
	return Cast<ALadicaBase>(GetPawn());
}

ALadicaBase * ADeffAIController::GetPlayerLadja() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ALadicaBase>(PlayerPawn);
}
