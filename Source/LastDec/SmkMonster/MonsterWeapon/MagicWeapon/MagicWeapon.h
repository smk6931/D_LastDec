// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LastDec/SmkMonster/MonsterWeapon/MonsterWeapon.h"
#include "MagicWeapon.generated.h"

UCLASS()
class LASTDEC_API AMagicWeapon : public AMonsterWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMagicWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
