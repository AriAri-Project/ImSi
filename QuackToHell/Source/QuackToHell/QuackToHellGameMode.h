// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "QuackToHellGameMode.generated.h"

UCLASS(minimalapi)
class AQuackToHellGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AQuackToHellGameMode();

//유진 part//
public:
	//디버깅 - 함수호출
	UFUNCTION(Exec, Category = "Command")
	void CallChat(FString SendTo, FString SendMessage);
	UFUNCTION(Exec, Category = "Command")
	void PrintChatHistory(FString Name);
};



