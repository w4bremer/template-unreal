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

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Testbed1Settings.generated.h"

const FString Testbed1LocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
class ITestbed1StructInterfaceInterface;
class ITestbed1StructArrayInterfaceInterface;

/**
 * Implements the settings for the Testbed1 plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TESTBED1_API UTestbed1Settings : public UObject
{
	GENERATED_UCLASS_BODY()

	// Callback used to validate the settings once the engine is available
	void ValidateSettingsPostEngineInit();

	// Choose the backend service for the logging decorator to use
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;

	// Choose the olink connection to use
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
	static TScriptInterface<ITestbed1StructInterfaceInterface> GetITestbed1StructInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetITestbed1StructArrayInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
};
