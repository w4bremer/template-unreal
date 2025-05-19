/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "AbstractTestbed1StructInterface.generated.h"

/**
 * Abstract UAbstractTestbed1StructInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1API_API UAbstractTestbed1StructInterface : public UGameInstanceSubsystem, public ITestbed1StructInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed1StructInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed1StructInterfaceSignals* _GetSignals() override;

	// methods
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	virtual FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncBool, return FTestbed1StructBool(););

	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt) override;
	virtual FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncInt, return FTestbed1StructInt(););

	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	virtual FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncFloat, return FTestbed1StructFloat(););

	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	virtual FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncString, return FTestbed1StructString(););

	// properties
	virtual FTestbed1StructBool GetPropBool() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropBool, return FTestbed1StructBool(););
	virtual void SetPropBool(const FTestbed1StructBool& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropBool, return;);

	virtual FTestbed1StructInt GetPropInt() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropInt, return FTestbed1StructInt(););
	virtual void SetPropInt(const FTestbed1StructInt& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropInt, return;);

	virtual FTestbed1StructFloat GetPropFloat() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropFloat, return FTestbed1StructFloat(););
	virtual void SetPropFloat(const FTestbed1StructFloat& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropFloat, return;);

	virtual FTestbed1StructString GetPropString() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropString, return FTestbed1StructString(););
	virtual void SetPropString(const FTestbed1StructString& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropString, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool{FTestbed1StructBool()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructBool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBool& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt{FTestbed1StructInt()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructInt GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructInt& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructFloat GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString{FTestbed1StructString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructString& InPropString);

private:
	// signals
	UPROPERTY()
	UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals;
};
