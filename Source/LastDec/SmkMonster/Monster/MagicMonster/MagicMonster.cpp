// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicMonster.h"

#include "LastDec/SmkMonster/MonsterFsm/MagicFsm/MagicFsm.h"
#include "LastDec/SmkMonster/MonsterFsm/SwordFsm/SwordFsm.h"


// Sets default values
AMagicMonster::AMagicMonster()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MonsterFsm = CreateDefaultSubobject<USwordFsm>("MonsterFSM");

}

// Called when the game starts or when spawned
void AMagicMonster::BeginPlay()
{
	Super::BeginPlay();
	MonsterHp = 500.0f;
}

// Called every frame
void AMagicMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMagicMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

