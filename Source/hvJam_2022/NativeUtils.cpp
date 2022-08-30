// Copyright Greg Fuller (vacui.dev) all rights reserved


#include "NativeUtils.h"

#include "CoreGlobals.h"

FString UNativeUtils::GetProjectVersion() {
	FString ProjectVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
	);
	return ProjectVersion;
}