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
class ITbSimpleVoidInterface;
class ITbSimpleSimpleInterface;
class ITbSimpleSimpleArrayInterface;
class ITbSimpleNoPropertiesInterface;
class ITbSimpleNoOperationsInterface;
class ITbSimpleNoSignalsInterface;
class ITbSimpleEmptyInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSimpleModuleFactory, Log, All);

class TBSIMPLECORE_API FTbSimpleModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTbSimpleVoidInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleVoidInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleSimpleInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleSimpleInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleSimpleArrayInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleSimpleArrayInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoPropertiesInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoPropertiesInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoOperationsInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoOperationsInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoSignalsInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoSignalsInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleEmptyInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleEmptyInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleVoidInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleArrayInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoPropertiesInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoOperationsInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoSignalsInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleEmptyInterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITbSimpleVoidInterface> GetTbSimpleVoidInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleInterface> GetTbSimpleSimpleInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleArrayInterface> GetTbSimpleSimpleArrayInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoPropertiesInterface> GetTbSimpleNoPropertiesInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoOperationsInterface> GetTbSimpleNoOperationsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoSignalsInterface> GetTbSimpleNoSignalsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleEmptyInterface> GetTbSimpleEmptyInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleVoidInterfaceFactoryFunction> TbSimpleVoidInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleInterfaceFactoryFunction> TbSimpleSimpleInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleArrayInterfaceFactoryFunction> TbSimpleSimpleArrayInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoPropertiesInterfaceFactoryFunction> TbSimpleNoPropertiesInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoOperationsInterfaceFactoryFunction> TbSimpleNoOperationsInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoSignalsInterfaceFactoryFunction> TbSimpleNoSignalsInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleEmptyInterfaceFactoryFunction> TbSimpleEmptyInterfaceFactories;
};
