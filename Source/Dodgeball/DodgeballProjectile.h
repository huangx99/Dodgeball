// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DodgeballProjectile.generated.h"

UCLASS()
class DODGEBALL_API ADodgeballProjectile : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dodgeball", meta=(AllowPrivateAccess="true"))
	class USphereComponent* SphereComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dodgeball", meta=(AllowPrivateAccess="true"))
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "DamageNum", meta = (AllowPrivateAccess = "true"))
	float Damage = 34.0f;

public:
	// Sets default values for this character's properties
	ADodgeballProjectile();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* otherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FORCEINLINE class UProjectileMovementComponent* GetProjrctileMovementComponent() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
