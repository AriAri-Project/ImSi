// Fill out your copyright notice in the Description page of Project Settings.


#include "QRecorderUserWidget.h"

void UQRecorderUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAPIOverview::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        //������ APIOverviewŬ������ ����
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            //��������Ʈ�� ���ε�
            APIActor->DialogDelegate->OnDialogTriggered.AddDynamic(this, &UQRecorderUserWidget::HandleDialogEvent);
            UE_LOG(LogTemp, Log, TEXT("Success Binding in QChatUserWidget: %s"), *APIActor->NPCName);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Fail!! Binding in QChatUserWidget"));
        }
    }

    // �� ���ڿ� 4���� �ʱ�ȭ
    NPCNames.Init(TEXT(""), 4);
}

//ê �̺�Ʈ�� �߻��Ҷ�����, ��ȭ��� ������.
//������ �������� �� �Ŵ����� �˾ƾߵ�..
void UQRecorderUserWidget::HandleDialogEvent(FString Name, FString Content)
{
    //������ ���ɱ� ���� �ӽ�����
    if (Name == "User") {
        UserText = "User: ";
        UserText += Content;
    }
    


    //���� ��ȭ����̸� ��ȭ��� �� ���� ����
    if (MapOfChats.FindKey(Name) == nullptr)
    {
        if (Name != "User") {

            //���� �迭�� �̸��ֱ�
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
    //������ ���� ������ ���ɾ��� ���� + ����� ���� ������ history�� ����
    if (MapOfChats.Contains(Name)) {
        FString ChatHistory = MapOfChats[Name];
        ChatHistory += UserText+"\n";
        ChatHistory += Name + ": " + Content+"\n";
        MapOfChats[Name] = ChatHistory;
    }
}
