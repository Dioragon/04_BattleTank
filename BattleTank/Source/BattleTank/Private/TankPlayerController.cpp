// Copyright Diogo Ribeiro 2020


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTrank() const
{
    return Cast<ATank>(GetPawn());
}