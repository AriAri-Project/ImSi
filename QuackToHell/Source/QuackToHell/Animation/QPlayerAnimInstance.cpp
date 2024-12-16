// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/QPlayerAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/QPlayer.h"

UQPlayerAnimInstance::UQPlayerAnimInstance(const FObjectInitializer& ObjectInitializer)
{

}

void UQPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AQPlayer>(TryGetPawnOwner());
	if (Character) {
		MovementComponent = Character->GetCharacterMovement();
	}
}

void UQPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Character == nullptr) {
		return;
	}
	if (MovementComponent == nullptr) {
		return;
	}

	Velocity = MovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();

	bShouldMove = (GroundSpeed > 3.f && MovementComponent->GetCurrentAcceleration() != FVector::ZeroVector);
}
