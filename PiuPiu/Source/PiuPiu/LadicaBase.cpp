// Fill out your copyright notice in the Description page of Project Settings.

#include "LadicaBase.h"
#include "DeffGun.h"
#include "Projectile.h"
// Sets default values
ALadicaBase::ALadicaBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}


// Called when the game starts or when spawned
void ALadicaBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALadicaBase::SetupGuns(UDeffGun* GunLeft, UDeffGun* GunRight)
{
	DefGunLeft = GunLeft;
	DefGunRight = GunRight;

	UE_LOG(LogTemp, Warning, TEXT(" Ladica %s - setting up the guns"), *(this->GetName()));
}

// Called every frame
void ALadicaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALadicaBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALadicaBase::Fire()
{

	if (!DefGunLeft || !DefGunRight) 
	{ 
		

		UE_LOG(LogTemp, Warning, TEXT(" Na ladici %s ni najdlu kanonov za strelat - nullptr"), *(this->GetName()));
		
		return; 
	}

	// TODO Spravi tu u posebi funkcijo
	auto projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		DefGunLeft->GetSocketLocation(FName("ProjectilePosition")),
		DefGunLeft->GetSocketRotation(FName("ProjectilePosition"))
		);

	projectile->LaunchProjectile(ProjectileSpeed);

	projectile=GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		DefGunRight->GetSocketLocation(FName("ProjectilePosition")),
		DefGunRight->GetSocketRotation(FName("ProjectilePosition"))
		);

	projectile->LaunchProjectile(ProjectileSpeed);
}

