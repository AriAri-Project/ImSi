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
	//����� - �Լ�ȣ��
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
	//�������Ʈ �������� ������ �гο��� GameWidgetClass�� ���� �������Ʈ�� �Ҵ�(TSubclassOf<UUserWidget> Ÿ���� UUserWidget�� ��ӹ޴� Ŭ������ ������ �� �ֽ��ϴ�.)
	//TSubclassOf<class UUserWidget>�� UUserWidget�� ��ӹ޴� Ŭ���� Ÿ�Ը� ������ �� �ִ� ������ ������
	TSubclassOf<class UUserWidget> GameWidgetClass;
	UPROPERTY()
	UQChatUserWidget* GameWidget;
	virtual void BeginPlay() override;
};
