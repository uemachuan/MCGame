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

	//�������ֵ
	if (CharacterOwner->Health <= 0.f)
	{
		//����Owner��������
		bOwnerDying = true;
	}

	//��ȡOwner���ٶȴ�С
	Speed = CharacterOwner->GetVelocity().Size();
}


