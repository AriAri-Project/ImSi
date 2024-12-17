// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QNonPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

AQNonPlayer::AQNonPlayer()
{
	Capsule = GetCapsuleComponent();
	Capsule->SetCapsuleHalfHeight(65);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -50));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	bIsTalkable = true;
	bIsTalking = false;
}

bool AQNonPlayer::GetIsTalking()
{
	return bIsTalking;
}

void AQNonPlayer::ActivateOutline()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void AQNonPlayer::DeactivateOutline()
{
	GetMesh()->SetRenderCustomDepth(false);
}
