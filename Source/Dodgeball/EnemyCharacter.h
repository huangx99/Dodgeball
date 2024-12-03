// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "DodgeballProjectile.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DODGEBALL_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess="true"))
	USceneComponent* SightSource;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ADodgeballProjectile> DodgeballClass;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	bool LookAtActor(AActor* TargetActor);

	bool CanSeeActor(AActor* TargetActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ThrowDodgeball();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	bool bCanSeePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;

	//扔球间隔
	float ThrowingInterval = 0.5f;


	AActor* Actor = nullptr;

	//定时器开始循环之前的初始间隔
	float ThrowingDelay = 0.5f;

};
