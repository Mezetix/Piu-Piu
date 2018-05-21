// Fill out your copyright notice in the Description page of Project Settings.

#include "LadicaBase.h"
#include "DeffGun.h"
#include "Projectile.h"
#include "ManeverTrusters.h"
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

void ALadicaBase::SetupManeverThrusters(UManeverTrusters * ManeverThrust)
{
	ManeverThrusters = ManeverThrust;

	UE_LOG(LogTemp, Warning, TEXT(" Ladica %s - setting up Manever Thrusters"), *(this->GetName()));
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

void ALadicaBase::TurnTowards(FVector TurnDirection)
{

	//UE_LOG(LogTemp, Warning, TEXT(" %s izvaja Turn Towars "), *(this->GetName()));


	// Work-out difference between current barrel roation, and AimDirection

	

	
	auto ladica = Cast<APawn>(this);
	//auto ladica = this->GetAllChildActors(otroc);
	if (!ladica)
	{

		UE_LOG(LogTemp, Warning, TEXT(" %s ne najde Ladice "), *(this->GetName()));

		return;
	}

	auto LadicaForwardRot = ladica->GetActorForwardVector().Rotation(); // fow vec od AILadje - rotacija je 0,0,0... 

	


	FVector PozTarceLocal = TurnDirection - ladica->GetNavAgentLocation();// vector od ladice do tarce
	
	auto TarcaAsRotator = PozTarceLocal.Rotation(); // Rotacija kjer se nahaja tarca
	
	auto DeltaRotator = TarcaAsRotator - LadicaForwardRot; // rotacija ki je potrebna da se obrnes proti tarci

	

	float RelativePitch = FMath::Clamp<float>(DeltaRotator.Pitch, -1, +1); // pitch ki je potreben  -- TODO Clamp bi lohk bil u samem manever thrusterju
	float RelativeYaw = FMath::Clamp<float>(DeltaRotator.Yaw, -1, +1); // yaw ki je potreben 
	float RelativeRoll = FMath::Clamp<float>(DeltaRotator.Roll, -1, +1); // roll je pa tku 0 zmeri... al pa ne


	// Manever thrusters
	if (ManeverThrusters)
	{
		
		
		ManeverThrusters->PitchUpAI(RelativePitch, ladica);
		ManeverThrusters->YawRightAI(RelativeYaw, ladica);
		ManeverThrusters->RollRightAI(RelativeRoll, ladica);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("manever thrusters = null n vem zakaj...  "), *(this->GetName()));
	}
	

	
	
 
}

