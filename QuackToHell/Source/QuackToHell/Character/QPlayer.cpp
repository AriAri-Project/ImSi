// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/QPlayer.h"
#include "Components/CapsuleComponent.h"

AQPlayer::AQPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

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
}

void AQPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AQPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
