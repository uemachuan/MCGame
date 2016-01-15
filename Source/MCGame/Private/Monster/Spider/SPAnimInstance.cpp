// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "SPAnimInstance.h"
#include "Public/Monster/MonsterCharacterBase.h"


void USPAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	APawn* Owner = TryGetPawnOwner();
	if (!IsValid(Owner))
	{
		return;
	}

	AMonsterCharacterBase* CharacterOwner = Cast<AMonsterCharacterBase>(Owner);
	if (CharacterOwner == nullptr)
	{
		return;
	}

	//检查生命值
	if (CharacterOwner->Health <= 0.f)
	{
		//设置Owner进入死亡
		bOwnerDying = true;
	}

	//获取Owner的速度大小
	Speed = CharacterOwner->GetVelocity().Size();
}


