// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "QNonPlayer.h"

AQPlayer::AQPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsTalking = false;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 560;
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0, 0));
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	Capsule = GetCapsuleComponent();
	Capsule->SetCapsuleRadius(15.0f);
	Capsule->SetCapsuleHalfHeight(30.0f);

	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -30.0f));

	TalkableRangeSphere = CreateDefaultSubobject<USphereComponent>("TalkableRangeSphere");
	TalkableRangeSphere->SetSphereRadius(100);
	TalkableRangeSphere->SetupAttachment(GetCapsuleComponent());

	// 오버랩 이벤트 바인딩
	TalkableRangeSphere->OnComponentBeginOverlap.AddDynamic(this, &AQPlayer::OnOverlapBegin);
	TalkableRangeSphere->OnComponentEndOverlap.AddDynamic(this, &AQPlayer::OnOverlapEnd);
}

TArray<AQNonPlayer*> AQPlayer::GetTalkableNPCs()
{
	return TalkableNPCs;
}

bool AQPlayer::GetIsTalking()
{
	return bIsTalking;
}

void AQPlayer::SetIsTalking(bool IsTalking)
{
	bIsTalking = IsTalking;
}

void AQPlayer::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                              class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// OtherActor가 NPC가 아니라면 return, 맞다면 대화가능여부 체크하고 TalkAbleNPCs에 추가
	AQNonPlayer* NonPlayer = Cast<AQNonPlayer>(OtherActor);
	if (NonPlayer == nullptr) return;
	if (!(NonPlayer->bIsTalkable) || NonPlayer->bIsTalking) return;
	TalkableNPCs.Add(NonPlayer);
	NonPlayer->ActivateOutline();
	
	// 디버깅 로그
	UE_LOG(LogTemp, Display, TEXT("AQPlayer::OnOverlapBegin %s"), *NonPlayer->GetName());
	for (AQNonPlayer* NPC : TalkableNPCs)
	{
		UE_LOG(LogTemp, Display, TEXT("TalkAbleNPCs : %s"), *NPC->GetName());
	}
}

void AQPlayer::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// OtherActor가 NPC가 아니라면 return, 맞다면 TalkAbleNPCs에서 제거
	AQNonPlayer* NonPlayer = Cast<AQNonPlayer>(OtherActor);
	if (NonPlayer == nullptr) return;
	
	UE_LOG(LogTemp, Display, TEXT("AQPlayer::OnOverlapEnd %s"), *NonPlayer->GetName());
	NonPlayer->bIsTalking = false;
	NonPlayer->DeactivateOutline();
	TalkableNPCs.Remove(Cast<AQNonPlayer>(NonPlayer));

	// 디버깅 로그
	if (TalkableNPCs.IsEmpty())
	{
		UE_LOG(LogTemp, Display, TEXT("TalkAbleNPCs : none"));
		return;
	}
	for (AQNonPlayer* NPC : TalkableNPCs)
	{
		UE_LOG(LogTemp, Display, TEXT("TalkAbleNPCs : %s"), *NPC->GetName());
	}
}
