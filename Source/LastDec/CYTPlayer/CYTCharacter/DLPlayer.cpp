// Fill out your copyright notice in the Description page of Project Settings.


#include "DLPlayer.h"


// Sets default values
ADLPlayer::ADLPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh>Tempmesh(TEXT("'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny.C'"));
	if (Tempmesh.Object != NULL)
	{
		GetMesh()->SetSkeletalMesh(Tempmesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0,0,-90), FRotator(0,-90,0));
	}

	
	
}

// Called when the game starts or when spawned
void ADLPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADLPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADLPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

