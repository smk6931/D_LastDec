// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LastDec/SmkMonster/MonsterFsm/MonsterFsm.h"
#include "MonsterAnim.generated.h"

/**
 * 
 */
UCLASS()
class LASTDEC_API UMonsterAnim : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeBeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	EMonsterFsmState AnimState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UMonsterFsm* MonsterFsm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	AMonster* Monster;
};
