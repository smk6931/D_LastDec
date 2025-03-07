// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterFsm.h"


// Sets default values for this component's properties
UMonsterFsm::UMonsterFsm()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMonsterFsm::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("UMonsterFsm::BeginPlay%s"),*UEnum::GetValueAsString(MonsterState));

	// Enum의 모든 값을 출력
	for (int32 i = 0; i <= static_cast<int32>(EMonsterFsmState::Move); i++)
	{
		EMonsterFsmState State = static_cast<EMonsterFsmState>(i);
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, State: %s"), i, *UEnum::GetValueAsString(State));
	}

	// ...
	
}


// Called every frame
void UMonsterFsm::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UMonsterFsm::ChangeState()
{
}

