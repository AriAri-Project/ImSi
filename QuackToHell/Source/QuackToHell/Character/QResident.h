// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/QNonPlayer.h"
#include "QResident.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API AQResident : public AQNonPlayer
{
	GENERATED_BODY()
	
public:
	// �ǰ��ο� ���� �˰��ִ� ������
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NPC Information")
	float KnowledgeAboutDefendant;

	void Move();
};
