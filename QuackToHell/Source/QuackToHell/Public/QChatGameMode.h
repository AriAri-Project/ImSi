// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <QChatUserWidget.h>
#include "QChatGameMode.generated.h"



/**
 * 
 */
UCLASS()
class QUACKTOHELL_API AQChatGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	//디버깅 - 함수호출
	UFUNCTION(Exec)
	void Test();
	UFUNCTION(Exec, Category = "Command")
	void CallChat(FString SendTo, FString SendMessage);
	UFUNCTION(Exec, Category = "Command")
	void PrintChatHistory(FString Name);
	AQChatGameMode();
protected:
	//TODO - Implement Widget Variables
	UPROPERTY(EditAnywhere, Category = "Widgets")
	//블루프린트 에디터의 디테일 패널에서 GameWidgetClass에 위젯 블루프린트를 할당(TSubclassOf<UUserWidget> 타입은 UUserWidget을 상속받는 클래스를 저장할 수 있습니다.)
	//TSubclassOf<class UUserWidget>는 UUserWidget을 상속받는 클래스 타입만 저장할 수 있는 안전한 포인터
	TSubclassOf<class UUserWidget> GameWidgetClass;
	UPROPERTY()
	UQChatUserWidget* GameWidget;
	virtual void BeginPlay() override;
};
