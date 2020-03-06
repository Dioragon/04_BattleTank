// Copyright Diogo Ribeiro 2020

#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());

    if (PlayerTank)
    {
        //TODO Move towards the player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        
        ControlledTank->Fire(); //TODO limit firing range
    }
}