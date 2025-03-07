// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "LastDec/SmkMonster/MonsterFsm/MonsterFsm.h"


// Sets default values
AMonster::AMonster()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MonsterFsm = CreateDefaultSubobject<UMonsterFsm>("MonsterFSM");
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh>tempMesh(TEXT("'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (tempMesh.Object)
	{
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
	}
	
	ConstructorHelpers::FClassFinder<UMonsterAnim>tempAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Monster/MonsterAnim.MonsterAnim_c'"));
	if (tempAnim.Class)
	{
		GetMesh()->SetAnimInstanceClass(tempAnim.Class);
	}
}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

