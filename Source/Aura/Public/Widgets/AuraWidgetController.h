#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

UCLASS()
class AURA_API UAuraWidgetController : public UObject {
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<class APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<class APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<class UAttributeSet> AttributeSet;
};
