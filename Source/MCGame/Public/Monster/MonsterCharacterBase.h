// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common/GameCommonCharacter.h"
#include "MonsterCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class MCGAME_API AMonsterCharacterBase : public AGameCommonCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterCharacterBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//收到任何伤害
	void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	
};
