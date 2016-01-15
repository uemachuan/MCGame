// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "Public/Monster/MonsterAIControllerBase.h"
#include "BehaviorTree/BehaviorTree.h"

// Sets default values
AMonsterAIControllerBase::AMonsterAIControllerBase()
{
}

// Called when the game starts or when spawned
void AMonsterAIControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTreeAsset)
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}
	
}


