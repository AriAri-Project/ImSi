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
	//NativeConstruct : AddToViewport �� ȣ��ȴ�. NativeOnInitialized �� �޸�, Viewport �� Add �� ������ �Ҹ���!
	virtual void NativeConstruct();
	
	//ä�� �̺�Ʈ �� ȣ��� �Լ�
	//ä���� �Ͼ ������, ��ȭ��Ͽ� add���־�� �Ѵ�.
	UFUNCTION()
	void HandleDialogEvent(FString Name, FString Content);

	//������ ���Ŵ� ���� �ӽ�����
	FString UserText = "";

};
