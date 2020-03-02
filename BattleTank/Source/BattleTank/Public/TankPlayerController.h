// Copyright Diogo Ribeiro 2020

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

	private:
		void AimTowardsCrosshair();
		bool GetSightRayHitLocation(FVector& HitLocation) const;

		ATank* GetControlledTank() const;
		
		UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

		UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
};
