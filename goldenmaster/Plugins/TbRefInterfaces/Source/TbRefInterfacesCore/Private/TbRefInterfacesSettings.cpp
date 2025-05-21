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
#include "TbRefInterfacesSettings.h"
#include "TbRefInterfaces/Generated/TbRefInterfacesFactory.h"
#include "TbRefInterfaces/Generated/TbRefInterfacesLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbRefInterfacesSettings::UTbRefInterfacesSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbRefInterfacesSettings::ValidateSettingsPostEngineInit);
}

void UTbRefInterfacesSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbRefInterfaces, Warning, TEXT("UTbRefInterfacesSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbRefInterfacesLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbRefInterfaces, Warning, TEXT("UTbRefInterfacesSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbRefInterfacesLocalBackendIdentifier;
	}
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> UTbRefInterfacesSettings::GetITbRefInterfacesSimpleLocalIfForLogging(FSubsystemCollectionBase& Collection)
{
	UTbRefInterfacesSettings* TbRefInterfacesSettings = GetMutableDefault<UTbRefInterfacesSettings>();

	FString BackendIdentifier = TbRefInterfacesSettings->TracerServiceIdentifier;

	if (TbRefInterfacesSettings->TracerServiceIdentifier == TbRefInterfacesLocalBackendIdentifier)
	{
		return FTbRefInterfacesModuleFactory::GetTbRefInterfacesSimpleLocalIfImplementation(TbRefInterfacesLocalBackendIdentifier, Collection);
	}

	if (TbRefInterfacesSettings->TracerServiceIdentifier != TbRefInterfacesLocalBackendIdentifier)
	{
		return FTbRefInterfacesModuleFactory::GetTbRefInterfacesSimpleLocalIfImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbRefInterfacesParentIf> UTbRefInterfacesSettings::GetITbRefInterfacesParentIfForLogging(FSubsystemCollectionBase& Collection)
{
	UTbRefInterfacesSettings* TbRefInterfacesSettings = GetMutableDefault<UTbRefInterfacesSettings>();

	FString BackendIdentifier = TbRefInterfacesSettings->TracerServiceIdentifier;

	if (TbRefInterfacesSettings->TracerServiceIdentifier == TbRefInterfacesLocalBackendIdentifier)
	{
		return FTbRefInterfacesModuleFactory::GetTbRefInterfacesParentIfImplementation(TbRefInterfacesLocalBackendIdentifier, Collection);
	}

	if (TbRefInterfacesSettings->TracerServiceIdentifier != TbRefInterfacesLocalBackendIdentifier)
	{
		return FTbRefInterfacesModuleFactory::GetTbRefInterfacesParentIfImplementation("olink", Collection);
	}

	return nullptr;
}
