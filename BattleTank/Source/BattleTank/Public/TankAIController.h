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
		ATank* GetControlledTank() const;

		virtual void BeginPlay() override;
};
