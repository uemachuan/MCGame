// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "Runtime/AIModule/Private/AIModulePrivate.h"
#include "Public/Monster/Task/BTTask_SearchRandomPointInRadius.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UBTTask_SearchRandomPointInRadius::UBTTask_SearchRandomPointInRadius()
{
	NodeName = "Search Random Point In Radius";
}

EBTNodeResult::Type UBTTask_SearchRandomPointInRadius::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = EBTNodeResult::Failed;
	UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	const AAIController* MyController = OwnerComp.GetAIOwner();

	if (MyController && MyBlackboard)
	{
		if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass())
		{
			FVector RandomPoint = FVector::ZeroVector;
			if (const APawn* MyPawn = MyController->GetPawn())
			{
				if (SearchRadius > 0.f)
				{
					RandomPoint = UNavigationSystem::GetRandomPointInNavigableRadius(GetWorld(), MyPawn->GetActorLocation(), SearchRadius);
				}
			}

			if (RandomPoint != FVector::ZeroVector)
			{
				MyBlackboard->SetValue<UBlackboardKeyType_Vector>(GetSelectedBlackboardKey(), RandomPoint);
				Result = EBTNodeResult::Succeeded;
			}
		}
		else if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
		{
			MyBlackboard->SetValue<UBlackboardKeyType_Object>(GetSelectedBlackboardKey(), UGameplayStatics::GetPlayerCharacter(this, 0));
			Result = EBTNodeResult::Succeeded;
		}
	}
	
	return Result;
}

FString UBTTask_SearchRandomPointInRadius::GetStaticDescription() const
{
	FString KeyDesc("invalid");
	if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass() || BlackboardKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
	{
		KeyDesc = GetSelectedBlackboardKey().ToString();
	}

	return FString::Printf(TEXT("%s: %s"), *Super::GetStaticDescription(), *KeyDesc);
}

/*
#if WITH_EDITOR

FName UBTTask_SearchRandomPointInRadius::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Task.PlaySound.Icon");
}

#endif	// WITH_EDITOR
*/


