// Copyright Diogo Ribeiro 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration
class UTankBarrel;

//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// UFUNCTION(BlueprintCallable, Categoy = Setup)
	// void SetTurretReference(UTankBarrel* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	
private:
	UTankBarrel* Barrel = nullptr;

	// UStaticMeshComponent* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
