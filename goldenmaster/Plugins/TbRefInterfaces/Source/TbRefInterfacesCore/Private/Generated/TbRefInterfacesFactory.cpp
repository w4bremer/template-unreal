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

#include "TbRefInterfaces/Generated/TbRefInterfacesFactory.h"
#include "TbRefInterfacesSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbRefInterfacesModuleFactory::FTbRefInterfacesSimpleLocalIfFactoryFunction> FTbRefInterfacesModuleFactory::TbRefInterfacesSimpleLocalIfFactories{};
TMap<FString, FTbRefInterfacesModuleFactory::FTbRefInterfacesParentIfFactoryFunction> FTbRefInterfacesModuleFactory::TbRefInterfacesParentIfFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbRefInterfacesModuleFactory);

bool FTbRefInterfacesModuleFactory::RegisterFactory(FString TypeIdentifier, FTbRefInterfacesSimpleLocalIfFactoryFunction FactoryFunction)
{
	if (TbRefInterfacesSimpleLocalIfFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbRefInterfacesModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbRefInterfacesSimpleLocalIfFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> FTbRefInterfacesModuleFactory::GetTbRefInterfacesSimpleLocalIfImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbRefInterfacesSimpleLocalIfFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbRefInterfacesSimpleLocalIfFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbRefInterfacesModuleFactory::RegisterFactory(FString TypeIdentifier, FTbRefInterfacesParentIfFactoryFunction FactoryFunction)
{
	if (TbRefInterfacesParentIfFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbRefInterfacesModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbRefInterfacesParentIfFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbRefInterfacesParentIf> FTbRefInterfacesModuleFactory::GetTbRefInterfacesParentIfImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbRefInterfacesParentIfFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbRefInterfacesParentIfFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
