// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "MonsterAIControllerBase.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class MCGAME_API AMonsterAIControllerBase : public AAIController
{
	GENERATED_BODY()
public:
	//ÐÐÎªÊ÷Asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BehaviorTree")
	class UBehaviorTree* BehaviorTreeAsset;
public:
	// Sets default values for this controller's properties
	AMonsterAIControllerBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
