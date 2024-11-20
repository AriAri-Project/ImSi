// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoStoryGenerator.h"


// Sets default values
AAutoStoryGenerator::AAutoStoryGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//StoryService 초기화
	StoryService = nullptr;

}

// Called when the game starts or when spawned
void AAutoStoryGenerator::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay Called"));

	//DefendantStoryService 인스턴스 생성
	//NewObject: UObject를 생성하기 위해 사용. 
	StoryService = NewObject<UDefendantStoryService>(this);

	if (StoryService) {
		UE_LOG(LogTemp, Display, TEXT("Defendant Story Service initialized."));

		//서비스 초기화
		OpenAI::ServiceSecrets Secrets; 
		StoryService->Init(Secrets);
		
		//JSON인자 생성
		TSharedPtr<FJsonObject> Args = MakeShareable(new FJsonObject());
		Args->SetStringField("name", "짱구");

		//서비스 호출
		StoryService->Call(Args, TEXT("TestToolID"));

		//호출 확인 로그
		UE_LOG(LogTemp, Display, TEXT("DefendantStoryService::Call invoked"));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Failed to create Defendant story service"));
	}


}

// Called every frame
void AAutoStoryGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

