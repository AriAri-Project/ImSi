// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QNonPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

AQNonPlayer::AQNonPlayer()
{
	Capsule = GetCapsuleComponent();
	Capsule->SetCapsuleHalfHeight(65);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -50));
	bIsTalkable = true;
	bIsTalking = false;
}

void AQNonPlayer::ActivateOutline()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void AQNonPlayer::DeactivateOutline()
{
	GetMesh()->SetRenderCustomDepth(false);
}
