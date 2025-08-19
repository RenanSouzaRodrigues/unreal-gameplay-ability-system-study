// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/AuraUserWidget.h"
void UAuraUserWidget::SetWidgetController(UObject* Controller) {
	this->WidgetController = Controller;
	this->InitWidgetController();
}
