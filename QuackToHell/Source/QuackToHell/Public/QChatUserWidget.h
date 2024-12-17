// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sample/APIOverview.h"
#include "Kismet/GameplayStatics.h"

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
	//NativeConstruct : AddToViewport 시 호출된다. NativeOnInitialized 와 달리, Viewport 에 Add 될 때마다 불린다!
	virtual void NativeConstruct();

private:

	
	//채팅 이벤트 시 호출될 함수
	UFUNCTION()
	void HandleDialogEvent(FString Name, FString Content);
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ChatWidget")
	FString SpeakingNPCTag = "";
public:
	//블루프린트에서 임플리멘테이션-> 따라서 cpp에서는 정의하지않음. 
	UFUNCTION(BlueprintImplementableEvent, Category = ChatWidget)
	void SettingUserChatText(const FString& NPCName, const FString& Content);
	//블루프린트에서 임플리멘테이션-> 따라서 cpp에서는 정의하지않음. 
	UFUNCTION(BlueprintImplementableEvent, Category = ChatWidget)
	void SettingNPCChatText(const FString& NPCName, const FString& Content);

	UFUNCTION(BlueprintCallable, Category = ChatWidget)
	void CallChat(FString SendTo, FString SendMessage);
};
