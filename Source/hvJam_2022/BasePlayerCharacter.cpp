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


void ABasePlayerCharacter::FellOutOfWorld(const UDamageType& dmgType) {
	FRotator newRot = GetActorRotation();
	newRot.Pitch = 0;
	TeleportTo(SafeLocation, newRot, false, false);
}