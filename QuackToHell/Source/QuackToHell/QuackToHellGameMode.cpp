// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuackToHellGameMode.h"
#include "QuackToHellCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include <Sample/APIOverview.h>

void AQuackToHellGameMode::CallChat(FString SendTo, FString SendMessage)
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

void AQuackToHellGameMode::PrintChatHistory(FString Tag) {
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

void AQuackToHellGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId,
    FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

APlayerController* AQuackToHellGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal,
    const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
    return NewPlayerController;
}

void AQuackToHellGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
}

void AQuackToHellGameMode::StartPlay()
{
    Super::StartPlay();
}


AQuackToHellGameMode::AQuackToHellGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Characters/BP_Lawyer.BP_Lawyer_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Script/Engine.Blueprint'/Game/Input/BP_PlayerController.BP_PlayerController_C'"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
