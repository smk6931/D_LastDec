// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MonsterFsm.generated.h"

UENUM(BlueprintType)
enum class EMonsterFsmState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Move,
	Attack,
	Magic,
	Avoid
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LASTDEC_API UMonsterFsm : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMonsterFsm();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

public:
	EMonsterFsmState MonsterState = EMonsterFsmState::Idle;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMonster* Monster;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ATestPlayer* TestPlayer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMonsterAnim* MonsterAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AAIController* Ai;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DistPlayer = 700.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DistRandom = 500.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DeTection = 750.0f;

	
	float CurrentTime = 0.0f;
	float MakeTime = 1.0f;
	

public:
	void AiMove();
	void ChangeState();

	UFUNCTION()
	void DetectionDrawDegCircle();
};
