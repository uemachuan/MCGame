// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameCommonCharacter.generated.h"

UCLASS()
class MCGAME_API AGameCommonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//生命值和生命最大值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float HealthMax;

public:
	// Sets default values for this character's properties
	AGameCommonCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
