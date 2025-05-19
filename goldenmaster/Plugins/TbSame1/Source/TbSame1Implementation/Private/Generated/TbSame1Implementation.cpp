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

#include "TbSame1/TbSame1Implementation.h"
#include "TbSame1/Generated/TbSame1Factory.h"
#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"
#include "Engine/Engine.h"
#include "TbSame1Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSame1Implementation"

void FTbSame1ImplementationModule::StartupModule()
{
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct1Interface>
		{
		return Cast<UTbSame1SameStruct1InterfaceImplementation>(Collection.InitializeDependency(UTbSame1SameStruct1InterfaceImplementation::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct2Interface>
		{
		return Cast<UTbSame1SameStruct2InterfaceImplementation>(Collection.InitializeDependency(UTbSame1SameStruct2InterfaceImplementation::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum1Interface>
		{
		return Cast<UTbSame1SameEnum1InterfaceImplementation>(Collection.InitializeDependency(UTbSame1SameEnum1InterfaceImplementation::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum2Interface>
		{
		return Cast<UTbSame1SameEnum2InterfaceImplementation>(Collection.InitializeDependency(UTbSame1SameEnum2InterfaceImplementation::StaticClass()));
	});
}

void FTbSame1ImplementationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSame1ImplementationModule, TbSame1Implementation)

#undef LOCTEXT_NAMESPACE
