// Fill out your copyright notice in the Description page of Project Settings.

#include "DodgeballFunctionLibrary.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"

bool UDodgeballFunctionLibrary::CanSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgonreActors)
{
	if (World == nullptr || TargetActor == nullptr)
		return false;


	FVector Start = Location;

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(IgonreActors);
	FHitResult Hit;
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;
	World->LineTraceSingleByChannel(Hit, Start, TargetActor->GetActorLocation(), Channel, CollisionQueryParams);

	return !Hit.bBlockingHit;
}
