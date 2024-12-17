// Fill out your copyright notice in the Description page of Project Settings.


#include "QCharacter.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AQCharacter::AQCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bTalkable = false;
}

// Called when the game starts or when spawned
void AQCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AQCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AQCharacter::GetTalkable()
{
	return bTalkable;
}