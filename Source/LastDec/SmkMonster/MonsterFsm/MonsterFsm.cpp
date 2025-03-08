// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterFsm.h"

#include "LastDec/SmkMonster/Character/TestPlayer.h"
#include "LastDec/SmkMonster/Monster/Monster.h"
#include "Math/UnitConversion.h"
#include "Runtime/AIModule/Classes/AIController.h"


// Sets default values for this component's properties
UMonsterFsm::UMonsterFsm()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMonsterFsm::BeginPlay()
{
	Super::BeginPlay();
	Monster = Cast<AMonster>(GetOwner());
	
	MonsterAnim = Cast<UMonsterAnim>(Monster->GetMesh()->GetAnimInstance());
	if (MonsterAnim)
	{
		UE_LOG(LogTemp, Warning, TEXT("Monster Casting Anim"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Monster Casting XXXX"));
	}
	Ai = Cast<AAIController>(Monster->GetController());
	TestPlayer = Cast<ATestPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	// Enum의 모든 값을 출력
	for (int32 i = 0; i <= int32(EMonsterFsmState::Avoid); i++)
	{
		EMonsterFsmState State =(EMonsterFsmState)(i);
		UE_LOG(LogTemp, Warning, TEXT("Index: %d, State: %s"), i, *UEnum::GetValueAsString(State));
	}
}


// Called every frame
void UMonsterFsm::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	MonsterStateLog();
	UE_LOG(LogTemp, Warning, TEXT("MonsterAnimSpeed%f"),MonsterAnim->Speed);

	switch (MonsterState)
	{
	case EMonsterFsmState::Idle:
		Idle();
		break;
	
	case EMonsterFsmState::AiMove:
		AiMove();
		break;
		
	case EMonsterFsmState::Attack:
		Attack();
		break;
	}
}

void UMonsterFsm::Idle()
{
	CurrentTime += GetWorld()->GetDeltaSeconds();
	if (CurrentTime > 2)
	{
		MonsterState = EMonsterFsmState::AiMove;
		
		CurrentTime = 0;
	}
}

void UMonsterFsm::AiMove()
{
	DetectionDrawDegCircle();
	
	// MonsterAnim->GetCharacterSpeed();
	
	FVector Distance = TestPlayer->GetActorLocation() - Monster->GetActorLocation();
	FVector DistNormal = Distance;
	DistNormal.Normalize();

	float RightDot = FVector::DotProduct(DistNormal,Monster->GetActorRightVector());
	float ForwardDot = FVector::DotProduct(DistNormal,Monster->GetActorForwardVector());
	
	float Dir = Distance.Size();
	
	if (DeTection > Dir && ForwardDot > 0)
	{
		Ai->MoveToLocation(TestPlayer->GetActorLocation(),30);

		// 거리가 공격범위 안에 들어왔을때
		if (Dir < AttackRange)
		{
			MonsterState = EMonsterFsmState::Attack;
		}
	}
	else
	{
		CurrentTime += GetWorld()->GetDeltaSeconds();
		if (CurrentTime > MakeTime)
		{
			float RandAngle = FMath::RandRange(0,360);
			float RandDist = FMath::RandRange(500,700);
			FVector Offset = FVector(FMath::Cos(RandAngle) * RandDist, FMath::Sin(RandAngle) * RandDist, 0.0f);
			Ai->MoveToLocation(Monster->GetActorLocation() + Offset, 100);

			CurrentTime = 0;
		}
	}
}

void UMonsterFsm::Attack()
{
	FVector Distance = TestPlayer->GetActorLocation() - Monster->GetActorLocation();
	float Dir = Distance.Size();
	
	if (AttackRange < Dir)
	{
		MonsterState = EMonsterFsmState::Idle;
	}
}

void UMonsterFsm::ChangeState()
{
}


// 디버그 CIrcle 출력
void UMonsterFsm::DetectionDrawDegCircle()
{
	if (GetWorld()) // 월드가 존재하는지 확인
	{
		DrawDebugCircle(
			GetWorld(),
			Monster->GetActorLocation(),  // 위치
			DeTection, //원의 반지름
			32,                // 선 개수 (32개면 부드러움)
			FColor::Red,       // 색상
			false,             // true이면 영구적, false이면 일정 시간 후 사라짐
			-1.0f,             // 지속 시간 (-1 = 한 프레임 동안만 표시)
			0,                 // 우선순위
			1.0f,              // 선의 두께
			FVector(Monster->GetActorForwardVector()),  // X축 기준
			FVector(Monster->GetActorRightVector())   // Y축 기준
		);
	}
}

// 생성시간
void UMonsterFsm::CreativeTime()
{
	CurrentTime = GetWorld()->GetTimeSeconds();
}

// 몬스터 상태 출력
void UMonsterFsm::MonsterStateLog()
{
	if (MonsterState != PreviousState)
	{
		FString StateName = StaticEnum<EMonsterFsmState>()->GetValueAsString(MonsterState);
		
		UE_LOG(LogTemp, Warning, TEXT("State: %s"), *UEnum::GetValueAsString((EMonsterFsmState)(int32(MonsterState))));
		
		// 이전 상태를 현재 상태로 업데이트
		PreviousState = MonsterState;
	}
}

