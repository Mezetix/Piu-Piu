// Fill out your copyright notice in the Description page of Project Settings.

#include "TurnToward.h"
#include "AIController.h"
#include "LadicaBase.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UTurnToward::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	

	auto ControledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto LadicaBaseAI = Cast<ALadicaBase>(ControledPawn);


	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();// tega ne rabis... pol bos mogu tarco brt iz table verjetno... al pa od ne vem kje... morde Pawn-GetTaget ()al neki tazga

	if (!PlayerPawn) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT(" Turn Toward AI %s beh ni najdu playerja "), *(PlayerPawn->GetName()));
		return EBTNodeResult::Failed; 
	
	}



	auto LadicaForwardRot = ControledPawn->GetActorForwardVector().Rotation(); // fow vec od AILadje - rotacija je 0,0,0... 




	FVector PozTarceLocal = PlayerPawn->GetActorLocation() - ControledPawn->GetNavAgentLocation();// vector od ladice do tarce

	

	auto TarcaAsRotator = PozTarceLocal.Rotation(); // Rotacija kjer se nahaja tarca


	auto DeltaRotator = TarcaAsRotator - LadicaForwardRot; // rotacija ki je potrebna da se obrnes proti tarci

	// za AI - UI Info
	LadicaBaseAI->Tarca = ControledPawn->GetNavAgentLocation();
	LadicaBaseAI->Heading = PozTarceLocal;
	LadicaBaseAI->RotToTarget = DeltaRotator;
	LadicaBaseAI->CommandName = FString("AI Turn Towards");
	
	// obrne smer obraèanja èe je veèje kot pol kroga
	if ((FGenericPlatformMath::Abs(DeltaRotator.Yaw)) >180)
	{
		DeltaRotator.Yaw = -DeltaRotator.Yaw;
	}


	if ((FGenericPlatformMath::Abs(DeltaRotator.Pitch)) >90)
	{
		DeltaRotator.Pitch = -DeltaRotator.Pitch;
	}


	// upoèasni zavijanje da neha nihat.. TODO - ni uredu... se kr niha pr naglih spremembah kota...

	float BreakeAngle = 35.0f;

	if (FGenericPlatformMath::Abs(DeltaRotator.Pitch) < BreakeAngle)
	{
		DeltaRotator.Pitch = DeltaRotator.Pitch / BreakeAngle;
	}

	if (FGenericPlatformMath::Abs(DeltaRotator.Yaw) < BreakeAngle)
	{
		DeltaRotator.Yaw = DeltaRotator.Yaw / BreakeAngle;
	}

	if (FGenericPlatformMath::Abs(DeltaRotator.Roll) < BreakeAngle)
	{
		DeltaRotator.Roll = DeltaRotator.Roll / BreakeAngle;
	}

	// preveri èe je kot veèji od 5 stopinj... pol se ni sucseed

	float RelativePitch = FMath::Clamp<float>(DeltaRotator.Pitch, -1, +1); // pitch ki je potreben  -- TODO Clamp bi lohk bil u samem manever thrusterju
	float RelativeYaw = FMath::Clamp<float>(DeltaRotator.Yaw, -1, +1); // yaw ki je potreben 
	float RelativeRoll = FMath::Clamp<float>(DeltaRotator.Roll, -1, +1); // roll je pa tku 0 zmeri... al pa ne


	LadicaBaseAI->PitchUpBase(RelativePitch);
	LadicaBaseAI->YawRightBase(RelativeYaw);
	LadicaBaseAI->RollRightBase(RelativeRoll);








	//LadicaBaseAI->TurnTowards(PlayerPawn->GetActorLocation());

	

	return EBTNodeResult::Succeeded;

}