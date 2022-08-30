// Copyright Greg Fuller (vacui.dev) all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeUtils.generated.h"

/**
 * 
 */
UCLASS()
class HVJAM_2022_API UNativeUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FString GetProjectVersion();
};
