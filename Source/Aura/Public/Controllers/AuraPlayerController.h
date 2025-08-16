// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController {
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Controller Inputs")
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category="Controller Inputs")
	TObjectPtr<class UInputAction> MovementInputAction;

private:
	TScriptInterface<class IAuraTargetInterface> LastTargetActor;
	TScriptInterface<IAuraTargetInterface> CurrentTargetActor;
	
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void Move(const struct FInputActionValue& InputActionValue);

private:
	void CursorTrace();
};
