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

#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1_data.h"
#include "Testbed1StructArrayInterfaceInterface.h"
#include "AbstractTestbed1StructArrayInterface.generated.h"

/**
 * Abstract UAbstractTestbed1StructArrayInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1_API UAbstractTestbed1StructArrayInterface : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigBool Signal")
	FTestbed1StructArrayInterfaceSigBoolDelegate SigBoolSignal;
	virtual FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigInt Signal")
	FTestbed1StructArrayInterfaceSigIntDelegate SigIntSignal;
	virtual FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigFloat Signal")
	FTestbed1StructArrayInterfaceSigFloatDelegate SigFloatSignal;
	virtual FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigString Signal")
	FTestbed1StructArrayInterfaceSigStringDelegate SigStringSignal;
	virtual FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropBool Changed")
	FTestbed1StructArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	virtual FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropInt Changed")
	FTestbed1StructArrayInterfacePropIntChangedDelegate PropIntChanged;
	virtual FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropFloat Changed")
	FTestbed1StructArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	virtual FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropString Changed")
	FTestbed1StructArrayInterfacePropStringChangedDelegate PropStringChanged;
	virtual FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override;
	virtual FTestbed1StructBool FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncBool_Implementation, return FTestbed1StructBool(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override;
	virtual FTestbed1StructBool FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncInt_Implementation, return FTestbed1StructBool(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;
	virtual FTestbed1StructBool FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncFloat_Implementation, return FTestbed1StructBool(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override;
	virtual FTestbed1StructBool FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncString_Implementation, return FTestbed1StructBool(););

	// properties
	virtual TArray<FTestbed1StructBool> GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropBool_Implementation, return TArray<FTestbed1StructBool>(););
	virtual void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropBool_Implementation, return;);

	virtual TArray<FTestbed1StructInt> GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropInt_Implementation, return TArray<FTestbed1StructInt>(););
	virtual void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropInt_Implementation, return;);

	virtual TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropFloat_Implementation, return TArray<FTestbed1StructFloat>(););
	virtual void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropFloat_Implementation, return;);

	virtual TArray<FTestbed1StructString> GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropString_Implementation, return TArray<FTestbed1StructString>(););
	virtual void SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropString_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override;

	virtual void BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override;

	virtual void BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	virtual void BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString) override;

	virtual void BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool) override;

	virtual void BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt) override;

	virtual void BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) override;

	virtual void BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructBool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructInt> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructFloat> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FTestbed1StructString>& InPropString);
};
