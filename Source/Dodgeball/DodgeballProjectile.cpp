// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeballProjectile.h"
#include "DodgeballCharacter.h"

#include "HealthComponent.h"

// Sets default values
ADodgeballProjectile::ADodgeballProjectile()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereComponent->SetSphereRadius(35.f);

	SphereComponent->SetCollisionProfileName(FName("DodgeBall"));

	SphereComponent->SetSimulatePhysics(true);

	SphereComponent->SetNotifyRigidBodyCollision(true);

	SphereComponent->OnComponentHit.AddDynamic(this, &ADodgeballProjectile::OnHit);

	RootComponent = SphereComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 2200.f;

}

void ADodgeballProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* otherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ADodgeballCharacter* Player = Cast<ADodgeballCharacter>(otherActor);
	if (Player != nullptr)
	{
		Destroy();

		UHealthComponent* HealthComponent = Player->FindComponentByClass<UHealthComponent>();
		if (HealthComponent != nullptr)
		{
			HealthComponent->LoseHealth(Damage);
		}
	}
}

UProjectileMovementComponent* ADodgeballProjectile::GetProjrctileMovementComponent() const
{
	return ProjectileMovement;
}

// Called when the game starts or when spawned
void ADodgeballProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.f);
}

// Called every frame
void ADodgeballProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADodgeballProjectile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

