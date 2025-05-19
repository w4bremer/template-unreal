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

#include "TbNames/TbNamesImplementation.h"
#include "TbNames/Generated/TbNamesFactory.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "Engine/Engine.h"
#include "TbNamesSettings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbNamesImplementation"

void FTbNamesImplementationModule::StartupModule()
{
	FTbNamesModuleFactory::RegisterFactory(TbNamesLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbNamesNamEs>
		{
		return Cast<UTbNamesNamEsImplementation>(Collection.InitializeDependency(UTbNamesNamEsImplementation::StaticClass()));
	});
}

void FTbNamesImplementationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbNamesImplementationModule, TbNamesImplementation)

#undef LOCTEXT_NAMESPACE
