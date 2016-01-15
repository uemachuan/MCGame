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
	//ӳ��Owner���ٶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float Speed;
	//���ΪTrue����ʾOwner��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	bool bOwnerDying;
public:
	// Native update override point
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
