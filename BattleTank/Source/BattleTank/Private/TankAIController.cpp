// Copyright Diogo Ribeiro 2020

#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController not targeting a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController targeting %s "), *PlayerTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ::ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn) {return nullptr;}
    return Cast<ATank>(PlayerPawn);
}