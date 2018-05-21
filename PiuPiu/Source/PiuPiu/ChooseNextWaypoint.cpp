// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	UE_LOG(LogTemp, Warning, TEXT("V exequte task smo"));
	
	// get Patrol route
	auto ControledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControledPawn->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute)) { return  EBTNodeResult::Failed; } // èe rute ni oz ne obstaja
	
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) // èe je prazna patrool roota - opozorilo izpisi
	{
		UE_LOG(LogTemp, Warning, TEXT("PatrolRoute  v %s je prazna"), *(ControledPawn->GetName()));
		return  EBTNodeResult::Failed;
	}
	
	


	// Set next waypoint
	auto BlacboardComp = OwnerComp.GetBlackboardComponent();
	auto index = BlacboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	BlacboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[index]);


	UE_LOG(LogTemp, Warning, TEXT("Index št. %i"), index);
	// Cycle the index

	auto NextIndex = (index + 1) % (PatrolPoints.Num());
	
	UE_LOG(LogTemp, Warning, TEXT("Next index= %i"), NextIndex);
	
	
	BlacboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), index);
	return EBTNodeResult::Succeeded;
}
