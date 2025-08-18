// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacterBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase() {
	PrimaryActorTick.bCanEverTick = true;
	this->Weapon = this->CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	this->Weapon->SetupAttachment(this->GetMesh(), FName("WeaponSocket"));
	this->Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AAuraCharacterBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const {
	return this->AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const {
	return this->AttributeSet;
}
