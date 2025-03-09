// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnim.h"
#include "LastDec/SmkMonster/Monster/Monster.h"

void UMonsterAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	
	Monster = Cast<AMonster>(GetOwningActor());
	if (Monster)
	{
		UE_LOG(LogTemp, Warning, TEXT("Monster::NativeBeginPlay"));
		
		MonsterFsm = Cast<UMonsterFsm>(Monster->MonsterFsm);
		UE_LOG(LogTemp, Warning, TEXT("MonsterFsm::NativeBeginPlay"));
	}
}

void UMonsterAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// UE_LOG(LogTemp, Warning, TEXT("AttackRange, %f"),MonsterFsm->AttackRange);
}

void UMonsterAnim::GetCharacterSpeed()
{
	if (Monster)
	{
		Speed = FVector::DotProduct(Monster->GetVelocity(), Monster->GetActorForwardVector());
	}
}
