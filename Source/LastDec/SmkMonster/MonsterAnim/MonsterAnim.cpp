// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnim.h"
#include "LastDec/SmkMonster/Monster/Monster.h"

void UMonsterAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Monster = Cast<AMonster>(TryGetPawnOwner());
	if (Monster != nullptr)
	{
		MonsterFsm = Cast<UMonsterFsm>(Monster->MonsterFsm);
	}
}

void UMonsterAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UMonsterAnim::GetCharacterSpeed()
{
	if (Monster)
	{
		Speed = FVector::DotProduct(Monster->GetVelocity(), Monster->GetActorForwardVector());
	}
}

// if (Monster)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Anim :: Monster->MonsterHp, %f"),Monster->MonsterHp);
// }
// if (MonsterFsm)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Anim :: MonsterFsm->AttackRange, %f"),MonsterFsm->AttackRange);
// }
	