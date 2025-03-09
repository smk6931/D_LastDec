// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterArrow.generated.h"

UCLASS()
class LASTDEC_API AMonsterArrow : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMonsterArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
