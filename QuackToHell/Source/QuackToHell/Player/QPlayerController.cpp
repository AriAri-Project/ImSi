// Fill out your copyright notice in the Description page of Project Settings.


#include "QPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Character/QNonPlayer.h"
#include "Character/QPlayer.h"
#include "GameFramework/PlayerController.h"

AQPlayerController::AQPlayerController(const FObjectInitializer& ObjectInitializer)
	: bRightMousePressed(false)
{

}

void AQPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AQPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Walk);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Turn);
		EnhancedInputComponent->BindAction(TalkAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Talk);
		EnhancedInputComponent->BindAction(EndTalkAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_EndTalk);

		InputComponent->BindAction("RightMouseButton", IE_Pressed, this, &AQPlayerController::RightMousePressed);
		InputComponent->BindAction("RightMouseButton", IE_Released, this, &AQPlayerController::RightMouseReleased);
	}
}

void AQPlayerController::Input_Walk(const FInputActionValue& InputValue)
{
	FVector2d InputVector = InputValue.Get<FVector2D>();

	if (TObjectPtr<ACharacter> PlayerCharacter = Cast<ACharacter>(GetPawn()))
	{
		FRotator ControlRotator = GetControlRotation();
		FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(FRotator(0, ControlRotator.Yaw, 0));
		FVector RightDirection = UKismetMathLibrary::GetRightVector(FRotator(0, ControlRotator.Yaw, 0));

		FVector MovementDirection = FVector::ZeroVector;

		if (InputVector.X != 0)
		{
			MovementDirection += ForwardDirection * InputVector.X;
			PlayerCharacter->AddMovementInput(ForwardDirection, InputVector.X);
		}

		if (InputVector.Y != 0)
		{
			MovementDirection += RightDirection * InputVector.Y;
			PlayerCharacter->AddMovementInput(RightDirection, InputVector.Y);
		}

		if (!MovementDirection.IsNearlyZero())
		{
			FRotator CurrentRotation = PlayerCharacter->GetActorRotation();
			FRotator TargetRotation = MovementDirection.Rotation();

			FRotator SmoothedRotation = FMath::RInterpTo(
				CurrentRotation,
				FRotator(0, TargetRotation.Yaw, 0),
				GetWorld()->GetDeltaSeconds(),
				10.0f 
			);

			PlayerCharacter->SetActorRotation(SmoothedRotation);
		}
	}
}

void AQPlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	if (bRightMousePressed)
	{
		// float Val = InputValue.Get<float>();
		FVector2d Val = InputValue.Get<FVector2D>();
		AddYawInput(Val.X);
		AddPitchInput(-Val.Y);
	}
}

void AQPlayerController::Input_Talk(const FInputActionValue& InputValue)
{
	// Player로부터 현재 대화가능한 NPC TArray받아옴.
	TObjectPtr<AQPlayer> PlayerCharacter = Cast<AQPlayer>(GetPawn());
	if (PlayerCharacter->GetIsTalking()) return; // Player가 이미 대화중이라면 return
	TArray<AQNonPlayer*> TalkableNPCs = PlayerCharacter->GetTalkableNPCs();

	// 디버깅 로그
	for (AQNonPlayer* NPC : TalkableNPCs)
	{
		UE_LOG(LogTemp, Display, TEXT("TalkAbleNPCs : %s"), *NPC->GetName());
	}

	// 대화 가능한 NPC가 없을때는 바로 return때리기
	if (TalkableNPCs.IsEmpty()) return;

	// 여기에 대화 구현. 항상 Array 첫번쨰 NPC와 대화. 
	CurrentTalkingNPC = TalkableNPCs[0];
	PlayerCharacter->SetIsTalking(true);
	CurrentTalkingNPC->bIsTalking = true;
	CurrentTalkingNPC->bIsTalkable = false;
}

void AQPlayerController::Input_EndTalk(const FInputActionValue& InputValue)
{
	TObjectPtr<AQPlayer> PlayerCharacter = Cast<AQPlayer>(GetPawn());
	if (!(PlayerCharacter->GetIsTalking())) return;

	// 디버깅 로그
	UE_LOG(LogTemp, Display, TEXT("CurrentTalkingNPC : %s"), *CurrentTalkingNPC->GetName());
	
	// Player가 Talking 중이라면 Talking 마무리 작업
	PlayerCharacter->SetIsTalking(false);
	CurrentTalkingNPC->bIsTalking = false;
	CurrentTalkingNPC->bIsTalkable = true;
}

void AQPlayerController::RightMousePressed()
{
	bRightMousePressed = true;
}

void AQPlayerController::RightMouseReleased()
{
	bRightMousePressed = false;
}