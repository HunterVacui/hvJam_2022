// Copyright Greg Fuller(vacui.dev) all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayerCharacter.generated.h"

UCLASS()
class HVJAM_2022_API ABasePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void FellOutOfWorld(const UDamageType& dmgType) override;

	UFUNCTION(BlueprintCallable)
	void FellOutOfWorld();

	// value between 0 and 1, where 1 is the player's full health bar
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void DoDamage(float amount);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector SafeLocation;
};
