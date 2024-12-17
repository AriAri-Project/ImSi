// Fill out your copyright notice in the Description page of Project Settings.


#include "QChatGameMode.h"



void AQChatGameMode::BeginPlay()
{
	if (GameWidgetClass != nullptr) {
		GameWidget = Cast<UQChatUserWidget>(CreateWidget(GetWorld(), GameWidgetClass));
		if (GameWidget != nullptr) {
			GameWidget->AddToViewport();
		}
	}
}


void AQChatGameMode::CallChat(FString SendTo, FString SendMessage)
{
    /*
        프롬프트초기화 막기
    */
    if (SendMessage.Contains(TEXT("Prompt"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("프롬프트"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("초기화"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("리셋"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("다시 시작"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("Reset"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("Remove"), ESearchCase::IgnoreCase) ||
        SendMessage.Contains(TEXT("지워"), ESearchCase::IgnoreCase))
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Invalid Message!!"));
        return;
    }

    /*
    1. 해당 인게임에서 내가 원하는 액터를 찾는다.
    2. 그 액터의 createChatCompletion메소드를 호출한다.
        query는 인자로 넣는다.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*SendTo), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // 해당 클래스의 메소드 호출
            APIActor->CreateChatCompletionRequest(SendMessage);
            UE_LOG(LogTemp, Log, TEXT("Called CreateChatCompletionRequest on Actor: %s"), *Actor->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Actor with tag '%s' is not of type AAPIOverview"), *SendTo);
        }
    }
}

void AQChatGameMode::PrintChatHistory(FString Tag) {
    /*
    1. 해당 인게임에서 내가 원하는 액터를 찾는다.
    2. 그 액터의 gethistory() 함수를 호출한다.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*Tag), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // 해당 클래스의 메소드 호출
            APIActor->GetHistory();
            UE_LOG(LogTemp, Log, TEXT("Called GetHistory on Actor: %s"), *Actor->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Actor with tag '%s' is not of type AAPIOverview"), *Tag);
        }
    }
}

AQChatGameMode::AQChatGameMode()
{

    UE_LOG(LogTemp, Log, TEXT("AMyChatGameMode Initialized"));

    //// 기본 PlayerController 클래스 설정
    // PlayerControllerClass = AMyPlayerController::StaticClass();
    //// 다른 기본 클래스도 설정 가능
    // DefaultPawnClass = nullptr;  // 기본 Pawn을 비활성화
    // HUDClass = nullptr;          // HUD 비활성화
}

void AQChatGameMode::Test() {
    UE_LOG(LogTemp, Log, TEXT("$$$$"));
}
