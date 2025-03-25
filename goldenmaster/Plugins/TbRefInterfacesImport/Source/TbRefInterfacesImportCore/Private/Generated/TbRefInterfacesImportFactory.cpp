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

#include "TbRefInterfacesImport/Generated/TbRefInterfacesImportFactory.h"
#include "TbRefInterfacesImportSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbRefInterfacesImportModuleFactory::FTbRefInterfacesImportCounterFactoryFunction> FTbRefInterfacesImportModuleFactory::TbRefInterfacesImportCounterFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbRefInterfacesImportModuleFactory);

bool FTbRefInterfacesImportModuleFactory::RegisterFactory(FString TypeIdentifier, FTbRefInterfacesImportCounterFactoryFunction FactoryFunction)
{
	if (TbRefInterfacesImportCounterFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbRefInterfacesImportModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbRefInterfacesImportCounterFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbRefInterfacesImportCounter> FTbRefInterfacesImportModuleFactory::GetTbRefInterfacesImportCounterImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbRefInterfacesImportCounterFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbRefInterfacesImportCounterFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
