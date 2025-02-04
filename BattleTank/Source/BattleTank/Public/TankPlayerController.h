// Copyright Diogo Ribeiro 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

//Responsible for helping the player aim.
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

	protected:
		UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	private:
		void AimTowardsCrosshair();
		bool GetSightRayHitLocation(FVector& HitLocation) const;
		bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

		UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;

		UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.4f;

		UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f;
};