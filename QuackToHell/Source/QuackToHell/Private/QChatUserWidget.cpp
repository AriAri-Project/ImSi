// Fill out your copyright notice in the Description page of Project Settings.


#include "QChatUserWidget.h"

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
