// Fill out your copyright notice in the Description page of Project Settings.


#include "LastDec/SmkMonster/MonsterArrow/MonsterArrow.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AMonsterArrow::AMonsterArrow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->InitSphereRadius(10.f);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	SetRootComponent(SphereComponent);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	ProjectileMove = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMove");
    ProjectileMove->bAutoActivate = false;  // 기본적으로 비활성화
    ProjectileMove->InitialSpeed = 500.f;
    ProjectileMove->MaxSpeed = 1000.f;
    ProjectileMove->bRotationFollowsVelocity = true;  // 방향을 속도에 맞게 회전
    ProjectileMove->bShouldBounce = false;     // 튕김 여부
    ProjectileMove->ProjectileGravityScale = 0.f; // 중력 영향 (0이면 무중력)
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/Monster/MonsterArrow/EditorSphere1.EditorSphere1'"));
	if (tempMesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(tempMesh.Object);
	}
}
void AMonsterArrow::BeginPlay()
{
	Super::BeginPlay();
	MagicArrowLaunch();
	UE_LOG(LogTemp, Display, TEXT("AMonsterArrow::BeginPlay"));
}

void AMonsterArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Display, TEXT("AMonsterArrow::BeginTick"));
	
	MyTimer(&AMonsterArrow::DestroyMagicArrow,3.0f);  // Timer 함수로 수정
}

void AMonsterArrow::MyTimer(void(AMonsterArrow::* Func)(), float MakeTime)
{
	CurrentTime += GetWorld()->GetDeltaSeconds();
	
	UE_LOG(LogTemp, Display, TEXT("AMonsterArrow::MyTimer%f"), CurrentTime);
	if (CurrentTime > MakeTime)
	{
		(this->*Func)(); // Func 호출
		UE_LOG(LogTemp, Display, TEXT("AMonsterArrow::Destroy"));
		CurrentTime = 0;
	}
}

void AMonsterArrow::MagicArrowLaunch()
{
	ProjectileMove->Velocity = GetActorForwardVector() * 500.0f;
	ProjectileMove->Activate();
}

void AMonsterArrow::DestroyMagicArrow()
{
	Destroy();  // 정확하게 액터를 파괴
}
// Called every frame
