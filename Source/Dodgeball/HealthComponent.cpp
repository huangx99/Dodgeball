// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "HealthInterface.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UHealthComponent::LoseHealth(float Amout)
{
	Health -= Amout;

	if (Health <= 0.0f)
	{
		Health = 0.0f;
		if (GetOwner()->Implements<UHealthInterface>())
		{
			IHealthInterface::Execute_OnDeath(GetOwner());
		}
	}
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

