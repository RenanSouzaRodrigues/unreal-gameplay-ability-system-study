// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interfaces/AuraTargetInterface.h"
#include "AuraEnemyCharacter.generated.h"

UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IAuraTargetInterface {
	GENERATED_BODY()

public:
	// interface methods
	UFUNCTION()
	virtual void HighlightActor() override;

	UFUNCTION()
	virtual void UnhighlightActor() override;
};
