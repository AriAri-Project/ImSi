// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sample/APIOverview.h"
#include "Kismet/GameplayStatics.h"
#include "QRecorderUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API UQRecorderUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:


	UPROPERTY(BlueprintReadOnly)
	
	TMap<FString, FString> MapOfChats;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> NPCNames;
	

private:
	//NativeConstruct : AddToViewport 시 호출된다. NativeOnInitialized 와 달리, Viewport 에 Add 될 때마다 불린다!
	virtual void NativeConstruct();
	
	//채팅 이벤트 시 호출될 함수
	//채팅이 일어날 때마다, 대화기록에 add해주어야 한다.
	UFUNCTION()
	void HandleDialogEvent(FString Name, FString Content);

	//유저의 말거는 내용 임시저장
	FString UserText = "";

};
