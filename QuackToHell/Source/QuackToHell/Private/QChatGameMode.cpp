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
    1. �ش� �ΰ��ӿ��� ���� ���ϴ� ���͸� ã�´�.
    2. �� ������ createChatCompletion�޼ҵ带 ȣ���Ѵ�.
        query�� ���ڷ� �ִ´�.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*SendTo), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // �ش� Ŭ������ �޼ҵ� ȣ��
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
    1. �ش� �ΰ��ӿ��� ���� ���ϴ� ���͸� ã�´�.
    2. �� ������ gethistory() �Լ��� ȣ���Ѵ�.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*Tag), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // �ش� Ŭ������ �޼ҵ� ȣ��
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

    //// �⺻ PlayerController Ŭ���� ����
    // PlayerControllerClass = AMyPlayerController::StaticClass();
    //// �ٸ� �⺻ Ŭ������ ���� ����
    // DefaultPawnClass = nullptr;  // �⺻ Pawn�� ��Ȱ��ȭ
    // HUDClass = nullptr;          // HUD ��Ȱ��ȭ
}

void AQChatGameMode::Test() {
    UE_LOG(LogTemp, Log, TEXT("$$$$"));
}
