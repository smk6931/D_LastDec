// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LastDec/SmkMonster/MonsterFsm/MonsterFsm.h"
#include "MagicFsm.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LASTDEC_API UMagicFsm : public UMonsterFsm
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMagicFsm();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Attack() override;
	virtual void AiMove() override;
};
