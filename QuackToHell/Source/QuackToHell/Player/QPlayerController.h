// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h" 
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Character/QNonPlayer.h"
#include "GameFramework/PlayerController.h"
#include <QChatUserWidget.h>

#include "QPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class QUACKTOHELL_API AQPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AQPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> WalkAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> TurnAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> TalkAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> EndTalkAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<AQNonPlayer> CurrentTalkingNPC;

private:
	bool bRightMousePressed;

	void Input_Walk(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);
	void Input_Talk(const FInputActionValue& InputValue);
	void Input_EndTalk(const FInputActionValue& InputValue);

	void RightMousePressed();
	void RightMouseReleased();

//��������//
protected:
	//TODO - Implement Widget Variables
	UPROPERTY(EditAnywhere, Category = "Widgets")
	//�������Ʈ �������� ������ �гο��� GameWidgetClass�� ���� �������Ʈ�� �Ҵ�(TSubclassOf<UUserWidget> Ÿ���� UUserWidget�� ��ӹ޴� Ŭ������ ������ �� �ֽ��ϴ�.)
	//TSubclassOf<class UUserWidget>�� UUserWidget�� ��ӹ޴� Ŭ���� Ÿ�Ը� ������ �� �ִ� ������ ������
	TSubclassOf<class UUserWidget> GameWidgetClass;
	UPROPERTY()
	UQChatUserWidget* GameWidget;
};
