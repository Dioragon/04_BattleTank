// Copyright Diogo Ribeiro 2020


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // auto Name = GetName();
    // UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"),*Name, Throttle);

    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}