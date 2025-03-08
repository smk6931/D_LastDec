// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnim.h"
#include "LastDec/SmkMonster/Monster/Monster.h"

void UMonsterAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Monster = Cast<AMonster>(TryGetPawnOwner());
	if (Monster)
	{
		UE_LOG(LogTemp, Warning, TEXT("Monster::NativeInitializeAnimation"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Monster::XXXXXXXXXXXX"));
	}
	// MonsterFsm = Cast<UMonsterFsm>(Monster->FindComponentByClass<UMonsterFsm>());
	MonsterFsm = Cast<UMonsterFsm>(Monster->MonsterFsm);
	if (MonsterFsm)
	{
		UE_LOG(LogTemp, Warning, TEXT("MonsterFsm::NativeInitializeAnimation"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MonsterFsm::XXXXXXXXXXXX"));
	}
}