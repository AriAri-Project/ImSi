// Fill out your copyright notice in the Description page of Project Settings.


#include "QChatUserWidget.h"

//채팅 in widget//
//트리거조건: Send버튼 누르면.
void UQChatUserWidget::CallChat(FString SendTo, FString SendMessage)
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



//대화 시 바인딩 된 함수: 대화내용 UI에 띄우게//
void UQChatUserWidget::HandleDialogEvent(FString Name, FString Content)
{
    UE_LOG(LogTemp, Display, TEXT("바인딩함수호출 in widget"));
    if (Name == "User") {
        SettingUserChatText(Name, Content);
    }
    else {
        SettingNPCChatText(Name, Content);
    }

}



//NativeConstruct : AddToViewport 시 호출된다. NativeOnInitialized 와 달리, Viewport 에 Add 될 때마다 불린다!
void UQChatUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAPIOverview::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        //액터의 APIOverview클래스에 접근
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            //델리게이트를 바인딩
            APIActor->DialogDelegate->OnDialogTriggered.AddDynamic(this, &UQChatUserWidget::HandleDialogEvent);
            UE_LOG(LogTemp, Log, TEXT("Success Binding in QChatUserWidget: %s"), *APIActor->NPCName);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Fail!! Binding in QChatUserWidget"));
        }
    }
}
