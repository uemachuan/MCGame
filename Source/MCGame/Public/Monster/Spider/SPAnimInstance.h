// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "SPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MCGAME_API USPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	//映射Owner的速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float Speed;
	//如果为True，表示Owner正在死亡
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	bool bOwnerDying;
public:
	// Native update override point
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
