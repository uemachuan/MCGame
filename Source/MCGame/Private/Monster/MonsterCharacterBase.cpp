// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "Public/Monster/MonsterCharacterBase.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
AMonsterCharacterBase::AMonsterCharacterBase()
{
	//static ConstructorHelpers::FClassFinder<AAIController> AIControllerBPClass(TEXT("/Game/McGame/Monster/Spider/Blueprints/SPControllerBP"));
	//if (AIControllerBPClass.Class != NULL)
	//{
	//	AIControllerClass = AIControllerBPClass.Class;
	//}

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonsterCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMonsterCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//收到任何伤害
void AMonsterCharacterBase::ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (!IsValid(this))
		return;

	if (Damage > 0.f)
	{
		Health -= Damage;

		if (Health <= 0.f)
		{
			UBlackboardComponent* BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(this);
			FName Name = UKismetSystemLibrary::MakeLiteralName(TEXT("bDead"));
			BlackboardComp->SetValueAsBool(Name, true);
		}
	}

	Super::ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser);
}

