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
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructInterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for Testbed1StructInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTestbed1StructInterfaceBPSignals : public UInterface
{
	GENERATED_BODY()
};

class TESTBED1API_API ITestbed1StructInterfaceBPSignals
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(const FTestbed1StructBool& ParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(const FTestbed1StructInt& ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const FTestbed1StructString& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed1|StructInterface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString);
};
