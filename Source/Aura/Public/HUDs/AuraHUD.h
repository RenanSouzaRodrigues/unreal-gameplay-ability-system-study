// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UAuraRootOverlayWidgetController;
struct FWidgetControllerParams;

UCLASS()
class AURA_API AAuraHUD : public AHUD {
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> RootOverlayInstance;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> RootOverlayWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAuraRootOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraRootOverlayWidgetController> OverlayWidgetControllerClass;
	
public:
	UAuraRootOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& params) const;
	
protected:
	virtual void BeginPlay() override;
	
};
