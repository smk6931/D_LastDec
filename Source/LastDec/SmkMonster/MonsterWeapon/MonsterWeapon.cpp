// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterWeapon.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMonsterWeapon::AMonsterWeapon()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
    MeshComp->SetupAttachment(Root);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComp");
	CapsuleComp->SetupAttachment(Root);
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>SwordMesh(TEXT("/Script/Engine.StaticMesh'/Game/Fab/Terraria__Muramasa/muramasa.muramasa'"));
	if (SwordMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(SwordMesh.Object);
		MeshComp->SetRelativeScale3D(FVector(WeaponScale,WeaponScale,WeaponScale));
	}
	
}

// Called when the game starts or when spawned
void AMonsterWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input

