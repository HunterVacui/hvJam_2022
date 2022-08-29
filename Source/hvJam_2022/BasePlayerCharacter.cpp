// Copyright Greg Fuller(vacui.dev) all rights reserved


#include "BasePlayerCharacter.h"

// Sets default values
ABasePlayerCharacter::ABasePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	SafeLocation = GetActorLocation();
}

void ABasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABasePlayerCharacter::FellOutOfWorld() {
	FRotator newRot = GetActorRotation();
	TeleportTo(SafeLocation, newRot, false, false);
	if (auto* controller = GetController()) {
		newRot.Pitch = 0;
		controller->SetControlRotation(newRot);
	}
}


void ABasePlayerCharacter::FellOutOfWorld(const UDamageType& dmgType) {
	FellOutOfWorld();
}