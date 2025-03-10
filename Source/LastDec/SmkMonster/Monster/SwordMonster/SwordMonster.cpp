// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordMonster.h"

#include "LastDec/SmkMonster/MonsterFsm/SwordFsm/SwordFsm.h"


// Sets default values
ASwordMonster::ASwordMonster()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MonsterFsm = CreateDefaultSubobject<USwordFsm>("SwordFsm");
}

// Called when the game starts or when spawned
void ASwordMonster::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASwordMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASwordMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

