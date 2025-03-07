// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterFsm.h"

#include "LastDec/SmkMonster/Character/TestPlayer.h"
#include "LastDec/SmkMonster/Monster/Monster.h"
#include "Runtime/AIModule/Classes/AIController.h"


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
	Monster = Cast<AMonster>(GetOwner());
	Ai = Cast<AAIController>(Monster->GetController());
	TestPlayer = Cast<ATestPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	// Enum의 모든 값을 출력
	for (int32 i = 0; i <= int32(EMonsterFsmState::Avoid); i++)
	{
		EMonsterFsmState State =(EMonsterFsmState)(i);
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, State: %s"), i, *UEnum::GetValueAsString(State));
	}
}


// Called every frame
void UMonsterFsm::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	AiMove();
}

void UMonsterFsm::AiMove()
{
	FVector Distance = TestPlayer->GetActorLocation() - Monster->GetActorLocation();
	Distance.Normalize();
	FVector Dist = Distance * DistPlayer;
	Ai->MoveToLocation(TestPlayer->GetActorLocation() - Dist);
	UE_LOG(LogTemp, Warning, TEXT("Move"));
}

void UMonsterFsm::ChangeState()
{
}

