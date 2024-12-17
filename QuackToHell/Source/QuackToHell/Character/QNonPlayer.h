// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/QCharacter.h"
#include "QNonPlayer.generated.h"

/**
 * 
 */

UCLASS()
class QUACKTOHELL_API AQNonPlayer : public AQCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<class UCapsuleComponent> Capsule;
	
public:
	AQNonPlayer();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString Personality;

	// 대화 가능 여부
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	bool bIsTalkable;

	// 대화 중인지에 대한 여부
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	bool bIsTalking;

	// 대화 쿨타임
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	float CooltimeForTalk;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString CurrentReply;
};
