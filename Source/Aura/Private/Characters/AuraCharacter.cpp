// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter() {
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	this->GetCharacterMovement()->bConstrainToPlane = true;
	this->GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationRoll = false;
	this->bUseControllerRotationYaw = false;
}
