// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DLPlayer.generated.h"

UCLASS()
class LASTDEC_API ADLPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADLPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//springArm 정의
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class USpringArmComponent* springArmComp;
	//camera 정의
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UCameraComponent* cameraComp;
	
	
	
};
