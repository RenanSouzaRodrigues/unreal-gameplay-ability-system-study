// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraEnemyCharacter.h"

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