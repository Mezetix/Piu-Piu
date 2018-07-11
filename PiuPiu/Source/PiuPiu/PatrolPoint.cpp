// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolPoint.h"


// Sets default values
APatrolPoint::APatrolPoint()
{
 

}
void APatrolPoint::BeginPlay()
{
	Super::BeginPlay();
}
// Called every frame
void APatrolPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
APatrolPoint::APatrolPoint(FVector lokacija, float blizina, int hitrost)
{
	Lokacija = lokacija;
	BlizinaTarce = blizina;
	Hitrost = hitrost;

	

	

}

FVector APatrolPoint::GetLokacija()
{
	
	return Lokacija;
}

float APatrolPoint::GetBlizinaTarce()
{
	return BlizinaTarce;
}

int APatrolPoint::GetHitrost()
{
	return Hitrost;
}

FString APatrolPoint::GetIme()
{
	return Ime;
}

void APatrolPoint::SetLokacija(FVector loka)
{
	Lokacija = loka;
}

void APatrolPoint::SetBlizinaTarce(float blizina)
{
	BlizinaTarce = blizina;
}

void APatrolPoint::SetHitrost(int HitrostProcent)
{
	Hitrost = HitrostProcent;
}

void APatrolPoint::SetIme(FString ime1)
{
	Ime = ime1;
}



//// Called every frame
//void APatrolPoint::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
