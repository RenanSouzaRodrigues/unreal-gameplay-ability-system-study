// Fill out your copyright notice in the Description page of Project Settings.


#include "States/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState() {
	this->SetNetUpdateFrequency(100.f);

	this->AbilitySystemComponent = this->CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	this->AbilitySystemComponent->SetIsReplicated(true);
	this->AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); // Mixed replicates only tho the owning client. Good for player controlled characters

	this->AttributeSet = this->CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const {
	return this->AbilitySystemComponent;
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const {
	return this->AttributeSet;
}

