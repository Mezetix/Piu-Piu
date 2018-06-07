// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyTo.h"
#include "AIController.h"
#include "LadicaBase.h"

EBTNodeResult::Type UFlyTo::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{



		auto ControledPawn = OwnerComp.GetAIOwner()->GetPawn();
		auto LadicaBaseAI = Cast<ALadicaBase>(ControledPawn);


		auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) {
			UE_LOG(LogTemp, Warning, TEXT(" Turn Toward AI %s beh ni najdu playerja "), *(PlayerPawn->GetName()));
			return EBTNodeResult::Failed;
		}


		LadicaBaseAI->TurnTowards(PlayerPawn->GetActorLocation());

		//TODO - verjetno vrne Bool, èe je vsej prblizn isti kot. Al pa spodi primerjaj in vrni succseed al pa in progres


		//FRotator curentRot = ControledPawn->GetActorForwardVector().Rotation();
		//	
		//FVector curentPoz = ControledPawn->GetActorLocation();

		//auto BlacboardComp = OwnerComp.GetBlackboardComponent();
		//FVector VTarca = BlacboardComp->GetValueAsVector(Tarca.SelectedKeyName);

		//FVector smerTarce = VTarca - curentPoz;
		//smerTarce.Normalize();
		//FRotator smerTarceRot = smerTarce.Rotation();

		//auto deltaRortator = smerTarceRot - curentRot;

		////TODO Preveri kako se tank obrne - kako zraèuna smer kam se mora obrnt... mislem da je aim at();

		return EBTNodeResult::Succeeded;

	
}
