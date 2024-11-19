// Fill out your copyright notice in the Description page of Project Settings.


#include "DefendantStoryService.h"

//초기화 함수
bool UDefendantStoryService::Init(const OpenAI::ServiceSecrets& Secrets)
{
	UE_LOG(LogTemp, Display, TEXT("UDefendantStoryService Init"));
	return true;
}

//해당 서비스에 대한 간략 설명
FString UDefendantStoryService::Description() const
{
	return "피고인에 대한 랜덤 스토리를 생성한다.";
}

//function의 이름
FString UDefendantStoryService::FunctionName() const
{
	return "GenerateDefendantStory";
}

//call함수: OpenAI요청 처리
void UDefendantStoryService::Call(const TSharedPtr<FJsonObject>& Args, const FString& ToolID)
{

}

//서비스 이름 반환
FString UDefendantStoryService::Name() const
{
	return "DefendantStory";
}

//ToolTip 설명 반환
FString UDefendantStoryService::TooltipDescription() const
{
	return "피고인에 대해 도덕적으로 판결하기에 모호한 스토리를 생성한다.";
}

//Function 만들기: Json 스키마 생성
FString UDefendantStoryService::MakeFunction() const
{
	//해당 스키마를 C++코드로 옮길 것이다. 
	/*{
		"type": "object",
		"properties" : {
			"name": {
				"type": "string",
				"description": "Name of the defendant."
			}
		},
		"required": ["name"]
	}*/



	return FString();
}
