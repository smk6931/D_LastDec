// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicWeapon.h"


// Sets default values
AMagicWeapon::AMagicWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp->SetStaticMesh(nullptr);
}

// Called when the game starts or when spawned
void AMagicWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

