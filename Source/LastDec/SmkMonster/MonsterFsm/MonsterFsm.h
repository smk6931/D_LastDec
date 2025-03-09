// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MonsterFsm.generated.h"

UENUM(BlueprintType)
enum class EMonsterFsmState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	AiMove,
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
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EMonsterFsmState MonsterState = EMonsterFsmState::Idle;
	
	EMonsterFsmState PreviousState = MonsterState;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMonster* Monster;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ATestPlayer* TestPlayer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMonsterAnim* MonsterAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AAIController* Ai;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMonsterArrow* MonsterArrow;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AMonsterArrow> ArrowFactory;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DistPlayer = 700.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DistRandom = 500.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DeTection = 750.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackRange = 250.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TargetDir;

	FTimerHandle MagicTimer;
	
	float CurrentTime = 0.0f;
	float MakeTime = 1.0f;
	

public:
	virtual void Idle();
	virtual void AiMove();
	virtual void Attack();
	void MagicAttack();
	void Magic();
	void Avoid();
	
	void ChangeState();

	UFUNCTION()
	void DetectionDrawDegCircle();
	void CreativeTime();
	void MonsterStateLog();
};
