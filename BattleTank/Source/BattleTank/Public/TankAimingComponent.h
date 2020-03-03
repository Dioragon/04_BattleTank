// Copyright Diogo Ribeiro 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	// void SetTurretReference(UStaticMeshComponent* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	
private:
	UStaticMeshComponent* Barrel = nullptr;

	// UStaticMeshComponent* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
