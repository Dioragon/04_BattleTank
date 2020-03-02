// Copyright Diogo Ribeiro 2020

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

	private:
		
		ATank* GetControlledTank() const;
		ATank* GetPlayerTank() const;
};
