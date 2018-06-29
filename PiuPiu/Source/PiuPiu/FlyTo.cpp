// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyTo.h"
#include "AIController.h"
#include "LadicaBase.h"

EBTNodeResult::Type UFlyTo::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{



		auto ControledPawn = OwnerComp.GetAIOwner()->GetPawn();
		auto LadicaBaseAI = Cast<ALadicaBase>(ControledPawn);


		/*auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) {
			UE_LOG(LogTemp, Warning, TEXT(" Turn Toward AI %s beh ni najdu playerja "), *(PlayerPawn->GetName()));
			return EBTNodeResult::Failed;
		}*/
		
		
		// - TODO dobi tar�o kamr gremo - blackboard stuff verjetnu...
		FVector Target= FVector(-2810.0f, 12364.0f, 9351.0f); // target 1 na sceni

		FRotator RazlikaKot = LadicaBaseAI->AngleToward(Target); // kot med tar�o in trenutnim hedingom

		float DovoljenKot = 45.0f;

		if (FGenericPlatformMath::Abs(RazlikaKot.Pitch) > DovoljenKot || FGenericPlatformMath::Abs(RazlikaKot.Yaw) > DovoljenKot) // roll ni va�n... smo lohk na glavo obrnjeni
		{
			// prevelik kot... najprej obrni

			LadicaBaseAI->TurnTowards(Target);

			return EBTNodeResult::InProgress;


		}


		FVector VecRazdaljaDoTarce = ControledPawn->GetNavAgentLocation() - Target;
		
		float razdaljaDoTarce = VecRazdaljaDoTarce.Dist(ControledPawn->GetNavAgentLocation(), Target);

		if(razdaljaDoTarce < 10000.0f)
		{
			LadicaBaseAI->ThrustStop();

			return EBTNodeResult::Succeeded;
				
		}

	
			LadicaBaseAI->ThrustMax();

			return EBTNodeResult::InProgress;

		


	

	
}
