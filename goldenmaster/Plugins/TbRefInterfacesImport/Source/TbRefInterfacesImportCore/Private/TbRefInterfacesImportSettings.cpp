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
#include "TbRefInterfacesImportSettings.h"
#include "TbRefInterfacesImport/Generated/TbRefInterfacesImportFactory.h"
#include "TbRefInterfacesImport/Generated/TbRefInterfacesImportLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbRefInterfacesImportSettings::UTbRefInterfacesImportSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbRefInterfacesImportSettings::ValidateSettingsPostEngineInit);
}

void UTbRefInterfacesImportSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbRefInterfacesImport, Warning, TEXT("UTbRefInterfacesImportSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbRefInterfacesImportLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbRefInterfacesImport, Warning, TEXT("UTbRefInterfacesImportSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbRefInterfacesImportLocalBackendIdentifier;
	}
}

TScriptInterface<ITbRefInterfacesImportCounter> UTbRefInterfacesImportSettings::GetITbRefInterfacesImportCounterForLogging(FSubsystemCollectionBase& Collection)
{
	UTbRefInterfacesImportSettings* TbRefInterfacesImportSettings = GetMutableDefault<UTbRefInterfacesImportSettings>();

	FString BackendIdentifier = TbRefInterfacesImportSettings->TracerServiceIdentifier;

	if (TbRefInterfacesImportSettings->TracerServiceIdentifier == TbRefInterfacesImportLocalBackendIdentifier)
	{
		return FTbRefInterfacesImportModuleFactory::GetTbRefInterfacesImportCounterImplementation(TbRefInterfacesImportLocalBackendIdentifier, Collection);
	}

	if (TbRefInterfacesImportSettings->TracerServiceIdentifier != TbRefInterfacesImportLocalBackendIdentifier)
	{
		return FTbRefInterfacesImportModuleFactory::GetTbRefInterfacesImportCounterImplementation("olink", Collection);
	}

	return nullptr;
}
