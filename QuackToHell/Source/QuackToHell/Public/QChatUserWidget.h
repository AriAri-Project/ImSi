// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sample/APIOverview.h"

#include "Engine/WorldInitializationValues.h"
#include "Kismet/GameplayStatics.h"
#include "QChatUserWidget.generated.h"

/**
 * chat widget
 */
UCLASS()
class QUACKTOHELL_API UQChatUserWidget : public UUserWidget
{
	GENERATED_BODY()
private:
	//NativeConstruct : AddToViewport �� ȣ��ȴ�. NativeOnInitialized �� �޸�, Viewport �� Add �� ������ �Ҹ���!
	virtual void NativeConstruct();
private:
	//ä�� �̺�Ʈ �� ȣ��� �Լ�
	UFUNCTION()
	void HandleDialogEvent(FString Name, FString Content);

public:
	//�������Ʈ���� ���ø������̼�-> ���� cpp������ ������������. 
	UFUNCTION(BlueprintImplementableEvent, Category = ChatWidget)
	void SettingUserChatText(const FString& NPCName, const FString& Content);
	//�������Ʈ���� ���ø������̼�-> ���� cpp������ ������������. 
	UFUNCTION(BlueprintImplementableEvent, Category = ChatWidget)
	void SettingNPCChatText(const FString& NPCName, const FString& Content);

};
