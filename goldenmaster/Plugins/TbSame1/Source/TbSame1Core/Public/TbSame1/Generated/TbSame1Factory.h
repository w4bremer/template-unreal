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
#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ScriptInterface.h"
#include "Runtime/Launch/Resources/Version.h"

class UGameInstance;
class FSubsystemCollectionBase;
class ITbSame1SameStruct1Interface;
class ITbSame1SameStruct2Interface;
class ITbSame1SameEnum1Interface;
class ITbSame1SameEnum2Interface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSame1ModuleFactory, Log, All);

class TBSAME1CORE_API FTbSame1ModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTbSame1SameStruct1InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame1SameStruct1Interface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame1SameStruct2InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame1SameStruct2Interface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame1SameEnum1InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame1SameEnum1Interface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame1SameEnum2InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame1SameEnum2Interface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTbSame1SameStruct1InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame1SameStruct2InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame1SameEnum1InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame1SameEnum2InterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITbSame1SameStruct1Interface> GetTbSame1SameStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameStruct2Interface> GetTbSame1SameStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum1Interface> GetTbSame1SameEnum1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum2Interface> GetTbSame1SameEnum2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTbSame1ModuleFactory::FTbSame1SameStruct1InterfaceFactoryFunction> TbSame1SameStruct1InterfaceFactories;
	static TMap<FString, FTbSame1ModuleFactory::FTbSame1SameStruct2InterfaceFactoryFunction> TbSame1SameStruct2InterfaceFactories;
	static TMap<FString, FTbSame1ModuleFactory::FTbSame1SameEnum1InterfaceFactoryFunction> TbSame1SameEnum1InterfaceFactories;
	static TMap<FString, FTbSame1ModuleFactory::FTbSame1SameEnum2InterfaceFactoryFunction> TbSame1SameEnum2InterfaceFactories;
};
