// Copyright Diogo Ribeiro 2020


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    IntendMoveForward(ForwardThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!LeftTrack || !RightTrack) {return;}
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
    //TODO prevent speed stacking from multiple controls
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!LeftTrack || !RightTrack) {return;}

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
    //TODO prevent speed stacking from multiple controls
}