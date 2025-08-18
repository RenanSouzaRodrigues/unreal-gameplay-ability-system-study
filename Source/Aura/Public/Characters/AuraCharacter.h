// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase {
	GENERATED_BODY()

public:
	AAuraCharacter();

	
	// ===========================================================
	// Server Methods
	// ===========================================================
	virtual void PossessedBy(AController* NewController) override;

	
	// ===========================================================
	// Client Methods
	// ===========================================================
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilitySystemComponent();
};
