// Fill out your copyright notice in the Description page of Project Settings.


#include "FGBaseAnimInstance.h"
#include "../FGBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFGBaseAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	checkf(TryGetPawnOwner()->IsA<AFGBaseCharacter>(), TEXT("UFGBaseAnimInstance::NativeBeginPlay() UFGBaseAnimInstance can be used only with AFGBaseCharacter"));

	CachedBaseCharacter = StaticCast<AFGBaseCharacter*>(TryGetPawnOwner()); // ����������� ���� ��� ��� �� ��������������� ������������� ������ �����
}

void UFGBaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (!CachedBaseCharacter.IsValid())
	{
		return;
	}

	UCharacterMovementComponent* CharacterMovement = CachedBaseCharacter->GetCharacterMovement();
	Speed = CharacterMovement->Velocity.Size();
	bIsFalling = CharacterMovement->IsFalling();
	bIsCrouching = CharacterMovement->IsCrouching();
}