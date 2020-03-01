// Copyright Diogo Ribeiro 2020


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s "), *ControlledTank->GetName());
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) {return;}

    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
        //Tell controlled tank to aim at this point
   
    }
    
}

//Get wolrd location of linetrace trhough crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    return true;
}