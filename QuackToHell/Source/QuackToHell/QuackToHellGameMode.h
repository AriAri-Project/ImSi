﻿// Copyright Epic Games, Inc. All Rights Reserved.

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

	// Login과 관련된 중요한 함수 3가지 (AGameModeBase로부터 override했음.)
	// PreLogin : 클라이언트의 접속 요청을 처리하는 함수. 서버의 경우에는 PreLogin과정을 생략한다. 자기 자신에 대한 접속 요청을 처리한다는건 불필요하기 때문에.
	// Login : 접속을 허용한 클라이언트에 대응하는 플레이어 컨트롤러를 만드는 함수
	// PostLogin : 플레이어의 입장을 위해 플레이어에 필요한 기본 설정을 모두 마무리하는 함수
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
	// 게임의 시작을 지시하는 함수
	// 게임모드의 StartPlay 함수를 통해 게임이 시작되면, 모든 액터들의 BeginPlay 함수가 실행된다.
	virtual void StartPlay() override;
};



