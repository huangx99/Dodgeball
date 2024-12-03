// Fill out your copyright notice in the Description page of Project Settings.


#include "wall.h"

// Sets default values
Awall::Awall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));

	RootComponent = RootScene;

}

// Called when the game starts or when spawned
void Awall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Awall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

