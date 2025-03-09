// Fill out your copyright notice in the Description page of Project Settings.


#include "LastDec/Public/SmkMonster/MonsterArrow/MonsterArrow.h"


// Sets default values
AMonsterArrow::AMonsterArrow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonsterArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

