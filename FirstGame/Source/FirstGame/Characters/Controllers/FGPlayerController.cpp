// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerController.h"
#include "../FGBaseCharacter.h"

void AFGPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	// ���� ����� �������� ���-�� ����������, �� ��� �� �������, ��������� ����� ���� ������
	CachedBaseCharacter = Cast<AFGBaseCharacter>(InPawn);
}

void AFGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AFGPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFGPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AFGPlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &AFGPlayerController::LookUp);
	InputComponent->BindAxis("TurnAtRate", this, &AFGPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUpAtRate", this, &AFGPlayerController::LookUpAtRate);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFGPlayerController::Jump);
}

void AFGPlayerController::MoveForward(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(Value);
	}
}

void AFGPlayerController::MoveRight(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(Value);
	}
}

void AFGPlayerController::Turn(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Turn(Value);
	}
}

void AFGPlayerController::LookUp(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(Value);
	}
}

void AFGPlayerController::TurnAtRate(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->TurnAtRate(Value);
	}
}

void AFGPlayerController::LookUpAtRate(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUpAtRate(Value);
	}
}

void AFGPlayerController::Jump()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}