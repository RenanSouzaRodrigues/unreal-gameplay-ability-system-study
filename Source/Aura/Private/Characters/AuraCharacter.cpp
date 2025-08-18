// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "States/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter() {
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	this->GetCharacterMovement()->bConstrainToPlane = true;
	this->GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationRoll = false;
	this->bUseControllerRotationYaw = false;
}

// runs on server
void AAuraCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	this->InitAbilitySystemComponent();
}


// runs on client
void AAuraCharacter::OnRep_PlayerState() {
	Super::OnRep_PlayerState();
	this->InitAbilitySystemComponent();
}

void AAuraCharacter::InitAbilitySystemComponent() {
	const auto playerState = this->GetPlayerState<AAuraPlayerState>();

	check(playerState);

	playerState->GetAbilitySystemComponent()->InitAbilityActorInfo(playerState, this);
	this->AbilitySystemComponent = this->GetAbilitySystemComponent();
	this->AttributeSet = this->GetAttributeSet();
}