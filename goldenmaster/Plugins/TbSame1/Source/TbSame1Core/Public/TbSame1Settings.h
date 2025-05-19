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
#include "TbSame1Settings.generated.h"

const FString TbSame1LocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
class ITbSame1SameStruct1Interface;
class ITbSame1SameStruct2Interface;
class ITbSame1SameEnum1Interface;
class ITbSame1SameEnum2Interface;

/**
 * Implements the settings for the TbSame1 plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TBSAME1CORE_API UTbSame1Settings : public UObject
{
	GENERATED_BODY()

	UTbSame1Settings(const FObjectInitializer& ObjectInitializer);

public:
	/** Callback used to validate the settings once the engine is available */
	void ValidateSettingsPostEngineInit();

	/** Choose the backend service for the logging decorator to use */
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;

	/** Choose the olink connection to use */
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
	static TScriptInterface<ITbSame1SameStruct1Interface> GetITbSame1SameStruct1InterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameStruct2Interface> GetITbSame1SameStruct2InterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum1Interface> GetITbSame1SameEnum1InterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum2Interface> GetITbSame1SameEnum2InterfaceForLogging(FSubsystemCollectionBase& Collection);

	/** Choose the heartbeat interval in milliseconds for the msgbus connection on the service side.
	 * On the service side this adjusts the heartbeat between client and service. The clients will receive the value from service.
	 * On the client side this adjusts how often discovery messages are sent until a service is connected.
	 */
	UPROPERTY(EditAnywhere, config, Category = MsgBusConnectionSetup, meta = (DisplayName = "Heartbeat interval (in milliseconds)"))
	uint32 MsgBusHeartbeatIntervalMS = 200;
};
