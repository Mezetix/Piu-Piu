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
		
		
		// - TODO dobi tarèo kamr gremo - blackboard stuff verjetnu...
		FVector Target; // target 1 na sceni
		
		Target.X = -2810.0f;
		Target.Y = 12364.0f;
		Target.Z = 9351.0f;

		

		FRotator RazlikaKot = LadicaBaseAI->AngleToward(Target); // kot med tarèo in trenutnim hedingom
		

		// za AI - UI Info
		LadicaBaseAI->Tarca = Target;
		LadicaBaseAI->Heading = Target - ControledPawn->GetNavAgentLocation();
		LadicaBaseAI->RotToTarget = RazlikaKot;
		LadicaBaseAI->CommandName = FName("AI Flay To");


		float DovoljenKot = 25.0f;

		if (FGenericPlatformMath::Abs(RazlikaKot.Pitch) > DovoljenKot || FGenericPlatformMath::Abs(RazlikaKot.Yaw) > DovoljenKot) // roll ni važn... smo lohk na glavo obrnjeni
		{
			// prevelik kot... najprej obrni

			LadicaBaseAI->TurnTowards(Target);

			return EBTNodeResult::Succeeded;


		}


		FVector VecRazdaljaDoTarce = ControledPawn->GetNavAgentLocation() - Target;
		
		float razdaljaDoTarce = VecRazdaljaDoTarce.Dist(ControledPawn->GetNavAgentLocation(), Target);

		if(razdaljaDoTarce < 5000.0f)
		{
			LadicaBaseAI->ThrustStop();

			return EBTNodeResult::Succeeded;
				
		}

		if (razdaljaDoTarce < 10000.0f)
		{
			LadicaBaseAI->SetThrust(LadicaBaseAI->GetMaxThrust() / 3);
		}
		else
		{
			LadicaBaseAI->ThrustMax();
		}
			return EBTNodeResult::Succeeded;

		


	

	
}
