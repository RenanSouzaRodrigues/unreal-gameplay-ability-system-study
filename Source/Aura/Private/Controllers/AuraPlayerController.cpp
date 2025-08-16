// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/AuraTargetInterface.h"

AAuraPlayerController::AAuraPlayerController() {
	this->bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime) {
	Super::PlayerTick(DeltaTime);

	this->CursorTrace();
}


void AAuraPlayerController::BeginPlay() {
	Super::BeginPlay();

	// I don't like this approach. This only works on debug mode. -Renan
	check(this->InputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	check(subsystem);

	subsystem->AddMappingContext(this->InputMappingContext, 0);

	this->bShowMouseCursor = true;
	this->DefaultMouseCursor = EMouseCursor::Type::Default;

	FInputModeGameAndUI inputMode;
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	inputMode.SetHideCursorDuringCapture(false);
	this->SetInputMode(inputMode);
}

void AAuraPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(this->InputComponent);

	// movement action
	enhancedInputComponent->BindAction(this->MovementInputAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
}

void AAuraPlayerController::Move(const struct FInputActionValue& InputActionValue) {
	const FVector2D axisValues = InputActionValue.Get<FVector2D>();
	const FRotator yawRotation(0.f, this->GetControlRotation().Yaw, 0.f);
	const FVector forwardVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	const FVector rightVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	if (auto playerPawn = this->GetPawn<APawn>()) {
		playerPawn->AddMovementInput(forwardVector, axisValues.X);
		playerPawn->AddMovementInput(rightVector, axisValues.Y);
	}
}

void AAuraPlayerController::CursorTrace() {
	FHitResult cursorHit;
	this->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, cursorHit);

	if (!cursorHit.bBlockingHit) return;

	if (!cursorHit.GetActor()->Implements<UAuraTargetInterface>()) {
		if (this->LastTargetActor) this->LastTargetActor->UnhighlightActor();
	}
	
	this->LastTargetActor = this->CurrentTargetActor;
	this->CurrentTargetActor = cursorHit.GetActor();

	if ((!this->LastTargetActor && !this->CurrentTargetActor) || (this->CurrentTargetActor == this->LastTargetActor)) return;
	
	if (this->CurrentTargetActor) this->CurrentTargetActor->HighlightActor();

	if (this->LastTargetActor) this->LastTargetActor->UnhighlightActor();
}
