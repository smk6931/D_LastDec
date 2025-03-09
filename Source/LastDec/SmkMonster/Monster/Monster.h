// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LastDec/SmkMonster/MonsterAnim/MonsterAnim.h"
#include "LastDec/SmkMonster/MonsterFsm/MonsterFsm.h"
#include "LastDec/SmkMonster/MonsterWeapon/MonsterWeapon.h"
#include "Monster.generated.h"

UCLASS()
class LASTDEC_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USkeletalMeshComponent* MonsterMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCapsuleComponent* MonsterCapsure;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMonsterFsm* MonsterFsm;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<class AMonsterWeapon> WeaponFactory;

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class AMonsterWeapon* MonsterWeapon;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MonsterHp = 300.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMonsterAnim* MonsterAnim;
};
