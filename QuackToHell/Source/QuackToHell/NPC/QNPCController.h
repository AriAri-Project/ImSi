// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "QNPCController.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API AQNPCController : public AAIController
{
	GENERATED_BODY()
public:
	AQNPCController(const FObjectInitializer& ObjectInitializer = FObjectInitializer());

	virtual void OnPossess(APawn* InPawn) override;
};
