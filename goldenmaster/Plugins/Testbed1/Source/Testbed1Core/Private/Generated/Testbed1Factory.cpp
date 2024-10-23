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

#include "Generated/Testbed1Factory.h"
#include "Testbed1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTestbed1ModuleFactory::FTestbed1StructInterfaceFactoryFunction> FTestbed1ModuleFactory::Testbed1StructInterfaceFactories{};
TMap<FString, FTestbed1ModuleFactory::FTestbed1StructArrayInterfaceFactoryFunction> FTestbed1ModuleFactory::Testbed1StructArrayInterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed1ModuleFactory);

bool FTestbed1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed1StructInterfaceFactoryFunction FactoryFunction)
{
	if (Testbed1StructInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed1StructInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1ModuleFactory::GetTestbed1StructInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed1StructInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed1StructInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTestbed1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed1StructArrayInterfaceFactoryFunction FactoryFunction)
{
	if (Testbed1StructArrayInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed1StructArrayInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1ModuleFactory::GetTestbed1StructArrayInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed1StructArrayInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed1StructArrayInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}