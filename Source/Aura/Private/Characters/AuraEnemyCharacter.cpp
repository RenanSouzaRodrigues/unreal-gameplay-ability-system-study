// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraEnemyCharacter.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"


AAuraEnemyCharacter::AAuraEnemyCharacter() {
	this->AbilitySystemComponent = this->CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	this->AbilitySystemComponent->SetIsReplicated(true);
	this->AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal); // Minimal is good for AI controlled characters.

	this->AttributeSet = this->CreateDefaultSubobject<UAttributeSet>("Attribute Set");
}

void AAuraEnemyCharacter::BeginPlay() {
	Super::BeginPlay();
	this->AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAuraEnemyCharacter::HighlightActor() {
	this->GetMesh()->SetRenderCustomDepth(true);
	this->GetMesh()->SetCustomDepthStencilValue(250);
	this->Weapon->SetRenderCustomDepth(true);
	this->Weapon->SetCustomDepthStencilValue(250);
}

void AAuraEnemyCharacter::UnhighlightActor() {
	this->GetMesh()->SetRenderCustomDepth(false);
	this->Weapon->SetRenderCustomDepth(false);
}