// Fill out your copyright notice in the Description page of Project Settings.

#include "LadicaBase.h"
#include "DeffGun.h"
#include "Projectile.h"
#include "ManeverTrusters.h"
#include "ManevertThrust.h"
#include "MainThrusters.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALadicaBase::ALadicaBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//LadicaMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Ladica"));
	//LadicaMesh->AddToRoot();
	
	//FVector pozicija;
	//pozicija.X = 300.0f;
	//pozicija.Y = 0.0f;
	//pozicija.Z = 0.0f;

	

	

	//pozicija.X = 0.0f;
	//pozicija.Y = -300.0f;
	//pozicija.Z = 0.0f;

	//LeftPoint->SetRelativeLocation(pozicija);

	//pozicija.Y = 300.0f;


	//FrontPoint = CreateDefaultSubobject<USceneComponent>(FName("FrontPoint"));

	//FrontPoint->SetRelativeLocation(pozicija);
	//FrontPoint->AttachTo(LadicaMesh);

	//BackPoint = CreateDefaultSubobject<USceneComponent>(FName("BackPoint"));
	//pozicija.X = -300.0f;
	//BackPoint->SetRelativeLocation(pozicija);
	//BackPoint->AttachTo(LadicaMesh);

	//LeftPoint = CreateDefaultSubobject<USceneComponent>(FName("LeftPoint"));
	//pozicija.X = 0.0f;
	//pozicija.Y = -300.0f;
	//pozicija.Z = 0.0f;
	//LeftPoint->SetRelativeLocation(pozicija);
	//LeftPoint->AttachTo(LadicaMesh);

	//RightPoint = CreateDefaultSubobject<USceneComponent>(FName("RightPoint"));
	//pozicija.Y = 300.0f;
	//RightPoint->SetRelativeLocation(pozicija);
	//RightPoint->AttachTo(LadicaMesh);

	

	LadicaManeverThrustComponent = CreateDefaultSubobject<UManevertThrust>(FName("ManeverThrust"));
	LadicaManeverThrustComponent->SetupThrusters(this);
	
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

void ALadicaBase::SetupLadica(UStaticMeshComponent * ladica)
{
	LadicaMesh = ladica;
	LadicaManeverThrustComponent->SetUpMesh(ladica);
	setup = true;


	


	UE_LOG(LogTemp, Warning, TEXT(" Ladica %s - setting up LadicaMesh, LadicaManeverThrustComponent"), *(this->GetName()));
}

void ALadicaBase::SetupManeverThrusters(UManeverTrusters * ManeverThrust)
{
	ManeverThrusters = ManeverThrust;

	UE_LOG(LogTemp, Warning, TEXT(" Ladica %s - setting up Manever Thrusters"), *(this->GetName()));
}

void ALadicaBase::MoveUpBase(float value)
{
	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetUpVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/

		
		LadicaMesh->AddForce(ForceAplied);
	}
	
}

void ALadicaBase::MoveRightBase(float value)
{
	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetRightVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/


		LadicaMesh->AddForce(ForceAplied);
	}
}

void ALadicaBase::MoveFrontBase(float value)
{
	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetForwardVector() * value * MaxSideForce* GetWorld()->GetDeltaSeconds();
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/


		LadicaMesh->AddForce(ForceAplied);
	}
}

void ALadicaBase::PitchUpBase(float value)
{
	
	if (value<-1.0f)
	{
		value = -1.0f;
	}
	if (value>1.0f)
	{
		value = 1.0f;
	}


	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetSocketRotation(FName("PitchUpFront")).Vector() *value * (MaxSideForce / 16) * GetWorld()->GetDeltaSeconds();
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/
		

		LadicaMesh->AddForceAtLocation(ForceAplied, LadicaMesh->GetSocketLocation(FName("PitchUpFront")));
		LadicaMesh->AddForceAtLocation(-(ForceAplied), LadicaMesh->GetSocketLocation(FName("PitchUpReare")));
		//LadicaMesh->AddForce(ForceAplied);
	}



	//LadicaManeverThrustComponent->PitchUp(value);
}

void ALadicaBase::YawRightBase(float value)
{
	
	if (value<-1.0f)
	{
		value = -1.0f;
	}
	if (value>1.0f)
	{
		value = 1.0f;
	}

	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetSocketRotation(FName("YawRightFront")).Vector() *value * (MaxSideForce / 16) * GetWorld()->GetDeltaSeconds();
		
		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/
		

		LadicaMesh->AddForceAtLocation(ForceAplied, LadicaMesh->GetSocketLocation(FName("YawRightFront"))); // isto spredi zadi sam da gre yaw - right vektor
		LadicaMesh->AddForceAtLocation(-1*(ForceAplied), LadicaMesh->GetSocketLocation(FName("YawRightBack")));
		//LadicaMesh->AddForce(ForceAplied);
	}


	//LadicaManeverThrustComponent->YawRight(value);
}

void ALadicaBase::RollRightBase(float value)
{

	if (value<-1.0f)
	{
		value = -1.0f;
	}
	if (value>1.0f)
	{
		value = 1.0f;
	}


	if (!LadicaMesh)
	{
		return;
	}
	if (value > 0 || value < 0)
	{
		FVector ForceAplied = LadicaMesh->GetUpVector() * value * (MaxSideForce / 16) * GetWorld()->GetDeltaSeconds();

		//FVector NewPos = ForceAplied + Ladica->GetActorLocation();
		/*Ladica->SetActorLocation(NewPos);
		APawn* LadicaP = Cast<APawn>(Ladica);*/


		LadicaMesh->AddForceAtLocation(ForceAplied, LadicaMesh->GetSocketLocation(FName("RollRightLeft"))); // isto spredi zadi sam da gre yaw - right vektor
		LadicaMesh->AddForceAtLocation(-1 * (ForceAplied), LadicaMesh->GetSocketLocation(FName("RollRightRight")));
		//LadicaMesh->AddForce(ForceAplied);
	}
}

// Called every frame
void ALadicaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Thrust();
}

void ALadicaBase::MojTick()
{

	
// TODO - briši --- verjetnu ne bomo rabl
	
}
void ALadicaBase::Thrust()
{

	if (GetCurrentThrust() > 0.0f)
	{
		FVector fowVec = LadicaMesh->GetForwardVector();
		FVector FotceToAdd = fowVec * GetCurrentThrust()  * GetWorld()->GetDeltaSeconds();

		LadicaMesh->AddForce(FotceToAdd);
	}

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
	
	

	
	// obrne smer obraèanja èe je veèje kot pol kroga
	if((FGenericPlatformMath::Abs(DeltaRotator.Yaw)) >180)
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

	float RelativePitch = FMath::Clamp<float>(DeltaRotator.Pitch, -1, +1); // pitch ki je potreben  -- TODO Clamp bi lohk bil u samem manever thrusterju
	float RelativeYaw = FMath::Clamp<float>(DeltaRotator.Yaw, -1, +1); // yaw ki je potreben 
	float RelativeRoll = FMath::Clamp<float>(DeltaRotator.Roll, -1, +1); // roll je pa tku 0 zmeri... al pa ne


	
		
		PitchUpBase(RelativePitch);
		YawRightBase(RelativeYaw);
		RollRightBase(RelativeRoll);
	

	
	
 
}

UStaticMeshComponent * ALadicaBase::GetLadicaMesh()
{
	
	if (!LadicaMesh)
	{
		return nullptr;
	}
	return LadicaMesh;
}

void ALadicaBase::Yaw(float value)
{
	if (!LadicaManeverThrustComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ladica::Yaw nima thrustersov n vem zakaj"), *(this->GetName()));
		return;
	}
	LadicaManeverThrustComponent->YawRight(value);
}

FRotator ALadicaBase::AngleToward(FVector tarca)
{

	auto ladica = Cast<APawn>(this);
	FRotator LadicaForwardRot = ladica->GetActorForwardVector().Rotation(); // fow vec od AILadje - rotacija je 0,0,0... 




	FVector PozTarceLocal = tarca - ladica->GetNavAgentLocation();// vector od ladice do tarce

	auto TarcaAsRotator = PozTarceLocal.Rotation(); // Rotacija kjer se nahaja tarca


	auto DeltaRotator = TarcaAsRotator - LadicaForwardRot; // rotacija ki je potrebna da se obrnes proti tarci



	return DeltaRotator;
}



void ALadicaBase::ThrustMax()
{

	CurrentThrust = MaxThrustersForce;


}

void ALadicaBase::ThrustStop()
{

	CurrentThrust = 0.0f;


}

void ALadicaBase::ThrustUpStep()
{

	CurrentThrust = CurrentThrust + ThrustersStep;
	if (CurrentThrust > MaxThrustersForce)
	{
		CurrentThrust = MaxThrustersForce;
	}



}

void ALadicaBase::ThrustDownStep()
{
	CurrentThrust = CurrentThrust - ThrustersStep;
	if (CurrentThrust < 0.0f)
	{
		CurrentThrust = 0.0f;
	}



}

float ALadicaBase::GetCurrentThrust()
{
	return CurrentThrust;
}

float ALadicaBase::GetMaxThrust()
{
	return MaxThrustersForce;
}

void ALadicaBase::SetThrust(float Value)
{
	CurrentThrust = Value;
}

