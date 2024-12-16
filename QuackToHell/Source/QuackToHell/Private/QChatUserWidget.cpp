// Fill out your copyright notice in the Description page of Project Settings.


#include "QChatUserWidget.h"

void UQChatUserWidget::HandleDialogEvent(FString Name, FString Content)
{
    UE_LOG(LogTemp, Display, TEXT("���ε��Լ�ȣ�� in widget"));
    if (Name == "User") {
        SettingUserChatText(Name, Content);
    }
    else {
        SettingNPCChatText(Name, Content);
    }

}



//NativeConstruct : AddToViewport �� ȣ��ȴ�. NativeOnInitialized �� �޸�, Viewport �� Add �� ������ �Ҹ���!
void UQChatUserWidget::NativeConstruct()
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
            APIActor->DialogDelegate->OnDialogTriggered.AddDynamic(this, &UQChatUserWidget::HandleDialogEvent);
            UE_LOG(LogTemp, Log, TEXT("Success Binding in QChatUserWidget: %s"), *APIActor->NPCName);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Fail!! Binding in QChatUserWidget"));
        }
    }
}
