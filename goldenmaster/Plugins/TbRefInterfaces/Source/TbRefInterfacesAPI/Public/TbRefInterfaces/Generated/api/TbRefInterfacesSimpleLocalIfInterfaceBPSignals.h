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

#include "UObject/Interface.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesSimpleLocalIfInterfaceBPSignals.generated.h"

/**
 * Helper interface for TbRefInterfacesSimpleLocalIf events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbRefInterfacesSimpleLocalIfBPSignals : public UInterface
{
	GENERATED_BODY()
};

class TBREFINTERFACESAPI_API ITbRefInterfacesSimpleLocalIfBPSignals
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "On IntSignal Signal")
	void OnIntSignalSignal(int32 Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "On Property IntProperty Changed")
	void OnIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty);
};
