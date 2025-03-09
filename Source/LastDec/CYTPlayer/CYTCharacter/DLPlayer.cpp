// Fill out your copyright notice in the Description page of Project Settings.


#include "DLPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ADLPlayer::ADLPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 메쉬 생성
	ConstructorHelpers::FObjectFinder<USkeletalMesh>Tempmesh(TEXT("'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (Tempmesh.Object != NULL)
	{
		GetMesh()->SetSkeletalMesh(Tempmesh.Object);
		// 메쉬 (위치,방향) 설정
		GetMesh()->SetRelativeLocationAndRotation(FVector(0,0,-90), FRotator(0,-90,0));
	}

	// 스프링암 컴포넌트 생성
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	// 스프링암 부모설정
	springArmComp->SetupAttachment(RootComponent);
	// 스프링암 위치 설정
	springArmComp->SetRelativeLocation(FVector(0, 70, 50));

	// 카메라 컴포넌트 생성
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	cameraComp->SetupAttachment(springArmComp);
	
	
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

