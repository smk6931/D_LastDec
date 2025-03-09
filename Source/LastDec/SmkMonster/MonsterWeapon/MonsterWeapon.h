// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterWeapon.generated.h"

UCLASS()
class LASTDEC_API AMonsterWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	UPROPERTY(EditAnywhere,Blueprintable)
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere,Blueprintable)
	class USceneComponent* Root;

	UPROPERTY(EditAnywhere,Blueprintable)
	class UCapsuleComponent* CapsuleComp;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float WeaponScale = 0.01f;
};
