// Fill out your copyright notice in the Description page of Project Settings.


#include "QPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "InputMappingContext.h"
#include "InputAction.h"
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
		UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("PlayerController BeginPlay"));
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AQPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("PlayerController SetupInputComponent"));
		EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Walk);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Turn);
		EnhancedInputComponent->BindAction(TalkAction, ETriggerEvent::Triggered, this, &AQPlayerController::Input_Talk);

		InputComponent->BindAction("RightMouseButton", IE_Pressed, this, &AQPlayerController::RightMousePressed);
		InputComponent->BindAction("RightMouseButton", IE_Released, this, &AQPlayerController::RightMouseReleased);
	}
}

void AQPlayerController::Input_Walk(const FInputActionValue& InputValue)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Lets Move!"));

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
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("PlayerController Input_Turn"));
	if (bRightMousePressed)
	{
		// float Val = InputValue.Get<float>();
		FVector2d Val = InputValue.Get<FVector2D>();
		AddYawInput(Val.X);
		AddPitchInput(-Val.Y);
	}
}

//eŰ ������ ��// 
void AQPlayerController::Input_Talk(const FInputActionValue& InputValue)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Lets Talk!"));
	//if�� ������ �Ŀ� ����: AQNonPlayer��� Ŭ���� �Ѱ��شٰ� �����ϰ� �ֱ�. 
	if (GameWidgetClass != nullptr) {
		GameWidget = Cast<UQChatUserWidget>(CreateWidget(GetWorld(), GameWidgetClass));
		if (GameWidget != nullptr) {
			GameWidget->AddToViewport();
			//***�ӽ�***//
			GameWidget->SpeakingNPCTag = "Jury1";

			//�±� ���� �κ�//AActor�� ĳ�����Ͽ� ����
			//��ȭ�� NPC�� �±׸� ����, widget�� �±� ������ �ٲ۴�.
			/*if (NPC->ActorHasTag("Defendant"))
			{
				GameWidget->SpeakingNPCTag = "Defendant";
			}
			if (NPC->ActorHasTag("Resident"))
			{
				GameWidget->SpeakingNPCTag = "Resident";
			}
			if (NPC->ActorHasTag("Jury1"))
			{
				GameWidget->SpeakingNPCTag = "Jury1";
			}
			if (NPC->ActorHasTag("Jury2"))
			{
				GameWidget->SpeakingNPCTag = "Jury2";
			}*/
		}
	}
}

// esc ������ ��// 



void AQPlayerController::RightMousePressed()
{
	bRightMousePressed = true;
}

void AQPlayerController::RightMouseReleased()
{
	bRightMousePressed = false;
}