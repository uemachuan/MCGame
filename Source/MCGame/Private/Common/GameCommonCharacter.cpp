// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "public/Common/GameCommonCharacter.h"


// Sets default values
AGameCommonCharacter::AGameCommonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 1000.f;
	HealthMax = 1000.f;

}

// Called when the game starts or when spawned
void AGameCommonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCommonCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGameCommonCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

