// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChatGPT/BaseService.h"
#include "DefendantStoryService.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API UDefendantStoryService : public UBaseService
{
	GENERATED_BODY()
public:
    virtual bool Init(const OpenAI::ServiceSecrets& Secrets);

    virtual FString Description() const;
    virtual FString FunctionName() const;
    virtual void Call(const TSharedPtr<FJsonObject>& Args, const FString& ToolID);

    virtual FString Name() const;
    virtual FString TooltipDescription() const;

protected:
    virtual FString MakeFunction() const;
	
};
