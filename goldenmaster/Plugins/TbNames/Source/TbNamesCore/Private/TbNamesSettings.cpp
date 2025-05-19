/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "TbNamesSettings.h"
#include "TbNames/Generated/TbNamesFactory.h"
#include "TbNames/Generated/TbNamesLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbNamesSettings::UTbNamesSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbNamesSettings::ValidateSettingsPostEngineInit);
}

void UTbNamesSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbNames, Warning, TEXT("UTbNamesSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbNamesLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbNames, Warning, TEXT("UTbNamesSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbNamesLocalBackendIdentifier;
	}
}

TScriptInterface<ITbNamesNamEs> UTbNamesSettings::GetITbNamesNamEsForLogging(FSubsystemCollectionBase& Collection)
{
	UTbNamesSettings* TbNamesSettings = GetMutableDefault<UTbNamesSettings>();

	FString BackendIdentifier = TbNamesSettings->TracerServiceIdentifier;

	if (TbNamesSettings->TracerServiceIdentifier == TbNamesLocalBackendIdentifier)
	{
		return FTbNamesModuleFactory::GetTbNamesNamEsImplementation(TbNamesLocalBackendIdentifier, Collection);
	}

	if (TbNamesSettings->TracerServiceIdentifier != TbNamesLocalBackendIdentifier)
	{
		return FTbNamesModuleFactory::GetTbNamesNamEsImplementation("olink", Collection);
	}

	return nullptr;
}
