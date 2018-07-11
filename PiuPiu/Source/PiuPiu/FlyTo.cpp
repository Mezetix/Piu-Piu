// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyTo.h"
#include "AIController.h"
#include "LadicaBase.h"
#include "PatrolPoint.h"

EBTNodeResult::Type UFlyTo::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{



		auto ControledPawn = OwnerComp.GetAIOwner()->GetPawn();
		auto LadicaBaseAI = Cast<ALadicaBase>(ControledPawn);


		/*auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) {
			UE_LOG(LogTemp, Warning, TEXT(" Turn Toward AI %s beh ni najdu playerja "), *(PlayerPawn->GetName()));
			return EBTNodeResult::Failed;
		}*/
		
		float hitrost = LadicaBaseAI->GetMaxThrust() / 100.0f*LadicaBaseAI->ActivePatrolPoint->GetHitrost();
		// - TODO dobi tarèo kamr gremo - blackboard stuff verjetnu...
		FVector Target; // target 1 na sceni
		
		Target = LadicaBaseAI->ActivePatrolPoint->GetLokacija();

		

		FRotator RazlikaKot = LadicaBaseAI->AngleToward(Target); // kot med tarèo in trenutnim hedingom
		

		// za AI - UI Info
		LadicaBaseAI->Tarca = Target;
		LadicaBaseAI->Heading = Target - ControledPawn->GetNavAgentLocation();
		LadicaBaseAI->RotToTarget = RazlikaKot;
		LadicaBaseAI->CommandName = FString("AI Flay To ") + ( LadicaBaseAI->ActivePatrolPoint->GetIme());


		float DovoljenKot = 25.0f;

		if (FGenericPlatformMath::Abs(RazlikaKot.Pitch) > DovoljenKot || FGenericPlatformMath::Abs(RazlikaKot.Yaw) > DovoljenKot) // roll ni važn... smo lohk na glavo obrnjeni
		{
			// prevelik kot... najprej obrni

			LadicaBaseAI->TurnTowards(Target);
			LadicaBaseAI->ThrustStop();
			return EBTNodeResult::Failed;


		}


		FVector VecRazdaljaDoTarce = ControledPawn->GetNavAgentLocation() - Target;
		
		float razdaljaDoTarce = VecRazdaljaDoTarce.Dist(ControledPawn->GetNavAgentLocation(), Target);
		LadicaBaseAI->DistToTarget = razdaljaDoTarce;
		if(razdaljaDoTarce <  LadicaBaseAI->ActivePatrolPoint->GetBlizinaTarce())
		{
			LadicaBaseAI->ThrustStop();

			LadicaBaseAI->Fire();// TODO zbrisi... sam za foro

			LadicaBaseAI->NaslednjiPatrolPoint();
			return EBTNodeResult::Succeeded;
				
		}

		if (razdaljaDoTarce < 10000.0f)
		{
			LadicaBaseAI->SetThrust(hitrost / 3);
		}
		else
		{
			LadicaBaseAI->SetThrust(hitrost);
		}
			return EBTNodeResult::Succeeded;

		


	

	
}
