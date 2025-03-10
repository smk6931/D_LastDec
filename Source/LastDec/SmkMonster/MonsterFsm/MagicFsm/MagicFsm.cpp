// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicFsm.h"


// Sets default values for this component's properties
UMagicFsm::UMagicFsm()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMagicFsm::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AttackRange = 750.0f;
	DeTection = 1500.0f;
	
}


// Called every frame
void UMagicFsm::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("UMagicFsm::TickComponent"));

	// ...
}

void UMagicFsm::Attack()
{
	Super::Attack();
}
//
void UMagicFsm::AiMove()
{
	Super::AiMove();
}


