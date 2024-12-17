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

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString Personality;

	// ��ȭ ���� ����
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	bool bIsTalkable;

	// ��ȭ �������� ���� ����
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	bool bIsTalking;

	// ��ȭ ��Ÿ��
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	float CooltimeForTalk;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	FString CurrentReply;

};
