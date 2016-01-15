// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SearchRandomPointInRadius.generated.h"

class UBehaviorTreeComponent;
struct FBlackboardKeySelector;

/**
 * Search a point
 */
UCLASS()
class MCGAME_API UBTTask_SearchRandomPointInRadius : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_SearchRandomPointInRadius();

	/** Search radius */
	UPROPERTY(Category = Node, EditAnywhere)
	float SearchRadius;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;
/*
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR	
*/
};
