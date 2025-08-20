// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/AuraUserWidget.h"

void AAuraHUD::BeginPlay() {
	Super::BeginPlay();

	check(this->RootOverlayWidgetClass);

	this->RootOverlayInstance = CastChecked<UAuraUserWidget>(CreateWidget<UUserWidget>(this->GetWorld(), this->RootOverlayWidgetClass));
	this->RootOverlayInstance->AddToViewport();
}
