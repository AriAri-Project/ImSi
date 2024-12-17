// Fill out your copyright notice in the Description page of Project Settings.


#include "QRecorderUserWidget.h"

void UQRecorderUserWidget::NativeConstruct()
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
            APIActor->DialogDelegate->OnDialogTriggered.AddDynamic(this, &UQRecorderUserWidget::HandleDialogEvent);
            UE_LOG(LogTemp, Log, TEXT("Success Binding in QChatUserWidget: %s"), *APIActor->NPCName);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Fail!! Binding in QChatUserWidget"));
        }
    }

    // 빈 문자열 4개로 초기화
    NPCNames.Init(TEXT(""), 4);
}

//챗 이벤트가 발생할때마다, 대화기록 저장함.
//유저가 누구에게 말 거는지를 알아야됨..
void UQRecorderUserWidget::HandleDialogEvent(FString Name, FString Content)
{
    //유저의 말걸기 내용 임시저장
    if (Name == "User") {
        UserText = "User: ";
        UserText += Content;
    }
    


    //없는 대화기록이면 대화기록 맵 공간 생성
    if (MapOfChats.FindKey(Name) == nullptr)
    {
        if (Name != "User") {

            //네임 배열에 이름넣기
            for (int i = 0; i < NPCNames.Num(); i++) {
                if (NPCNames[i].IsEmpty()) {
                    NPCNames[i] = Name;
                    break;
                }
                if (NPCNames[i]==Name) {
                    break;
                }
            }
            if (!MapOfChats.Contains(Name)) {
                MapOfChats.Add(Name);
            }
        }
    }
    //응답이 오면 유저의 말걸었던 내용 + 응답온 내용 쌍으로 history에 저장
    if (MapOfChats.Contains(Name)) {
        FString ChatHistory = MapOfChats[Name];
        ChatHistory += UserText+"\n";
        ChatHistory += Name + ": " + Content+"\n";
        MapOfChats[Name] = ChatHistory;
    }
}
