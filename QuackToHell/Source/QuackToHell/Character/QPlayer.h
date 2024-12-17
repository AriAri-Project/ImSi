// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/QCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "QPlayer.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API AQPlayer : public AQCharacter
{
	GENERATED_BODY()
protected:
	AQPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "NPC Talk")
	TObjectPtr<class USphereComponent> TalkableRangeSphere;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC Talk")
	TArray<AQNonPlayer*> TalkableNPCs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC Talk")
	bool bIsTalking;
public:	
	UFUNCTION()
	TArray<AQNonPlayer*> GetTalkableNPCs();

	UFUNCTION()
	bool GetIsTalking();

	UFUNCTION()
	void SetIsTalking(bool IsTalking);
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
					  class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
