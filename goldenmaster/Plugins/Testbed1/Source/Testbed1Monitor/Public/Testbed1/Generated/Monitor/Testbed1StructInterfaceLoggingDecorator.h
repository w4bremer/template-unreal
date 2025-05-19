
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
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
#include "Testbed1StructInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1MONITOR_API UTestbed1StructInterfaceLoggingDecorator : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed1StructInterfaceLoggingDecorator();
	virtual ~UTestbed1StructInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void setBackendService(TScriptInterface<ITestbed1StructInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBool GetPropBool() const override;

	void SetPropBool(const FTestbed1StructBool& InPropBool) override;

	FTestbed1StructInt GetPropInt() const override;

	void SetPropInt(const FTestbed1StructInt& InPropInt) override;

	FTestbed1StructFloat GetPropFloat() const override;

	void SetPropFloat(const FTestbed1StructFloat& InPropFloat) override;

	FTestbed1StructString GetPropString() const override;

	void SetPropString(const FTestbed1StructString& InPropString) override;

	// operations
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigBool(const FTestbed1StructBool& InParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigInt(const FTestbed1StructInt& InParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const FTestbed1StructFloat& InParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigString(const FTestbed1StructString& InParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const FTestbed1StructBool& InPropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const FTestbed1StructInt& InPropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FTestbed1StructString& InPropString);
};
