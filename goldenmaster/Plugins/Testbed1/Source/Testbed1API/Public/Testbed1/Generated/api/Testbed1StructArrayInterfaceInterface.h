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
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Testbed1_data.h"
#include "Testbed1StructArrayInterfaceInterface.generated.h"

/**
 * Declaration for StructArrayInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigBoolDelegate, const TArray<FTestbed1StructBool>& /* ParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigBoolDelegateBP, const TArray<FTestbed1StructBool>&, ParamBool);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigIntDelegate, const TArray<FTestbed1StructInt>& /* ParamInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigIntDelegateBP, const TArray<FTestbed1StructInt>&, ParamInt);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigFloatDelegate, const TArray<FTestbed1StructFloat>& /* ParamFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigFloatDelegateBP, const TArray<FTestbed1StructFloat>&, ParamFloat);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigStringDelegate, const TArray<FTestbed1StructString>& /* ParamString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigStringDelegateBP, const TArray<FTestbed1StructString>&, ParamString);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigEnumDelegate, const TArray<ETestbed1Enum0>& /* ParamEnum */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigEnumDelegateBP, const TArray<ETestbed1Enum0>&, ParamEnum);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropBoolChangedDelegate, const TArray<FTestbed1StructBool>& /* PropBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropBoolChangedDelegateBP, const TArray<FTestbed1StructBool>&, PropBool);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropIntChangedDelegate, const TArray<FTestbed1StructInt>& /* PropInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropIntChangedDelegateBP, const TArray<FTestbed1StructInt>&, PropInt);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropFloatChangedDelegate, const TArray<FTestbed1StructFloat>& /* PropFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropFloatChangedDelegateBP, const TArray<FTestbed1StructFloat>&, PropFloat);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropStringChangedDelegate, const TArray<FTestbed1StructString>& /* PropString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropStringChangedDelegateBP, const TArray<FTestbed1StructString>&, PropString);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropEnumChangedDelegate, const TArray<ETestbed1Enum0>& /* PropEnum */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropEnumChangedDelegateBP, const TArray<ETestbed1Enum0>&, PropEnum);

/**
 * Class UTestbed1StructArrayInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED1API_API UTestbed1StructArrayInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTestbed1StructArrayInterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "SigBool Signal")
	FTestbed1StructArrayInterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool)
	{
		OnSigBoolSignal.Broadcast(ParamBool);
		OnSigBoolSignalBP.Broadcast(ParamBool);
	}

	FTestbed1StructArrayInterfaceSigIntDelegate OnSigIntSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "SigInt Signal")
	FTestbed1StructArrayInterfaceSigIntDelegateBP OnSigIntSignalBP;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt)
	{
		OnSigIntSignal.Broadcast(ParamInt);
		OnSigIntSignalBP.Broadcast(ParamInt);
	}

	FTestbed1StructArrayInterfaceSigFloatDelegate OnSigFloatSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "SigFloat Signal")
	FTestbed1StructArrayInterfaceSigFloatDelegateBP OnSigFloatSignalBP;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat)
	{
		OnSigFloatSignal.Broadcast(ParamFloat);
		OnSigFloatSignalBP.Broadcast(ParamFloat);
	}

	FTestbed1StructArrayInterfaceSigStringDelegate OnSigStringSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "SigString Signal")
	FTestbed1StructArrayInterfaceSigStringDelegateBP OnSigStringSignalBP;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const TArray<FTestbed1StructString>& ParamString)
	{
		OnSigStringSignal.Broadcast(ParamString);
		OnSigStringSignalBP.Broadcast(ParamString);
	}

	FTestbed1StructArrayInterfaceSigEnumDelegate OnSigEnumSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "SigEnum Signal")
	FTestbed1StructArrayInterfaceSigEnumDelegateBP OnSigEnumSignalBP;
	/// C++ wrapper for BP functions to safely call SigEnumSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast SigEnum Signal")
	void BroadcastSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum)
	{
		OnSigEnumSignal.Broadcast(ParamEnum);
		OnSigEnumSignalBP.Broadcast(ParamEnum);
	}

	FTestbed1StructArrayInterfacePropBoolChangedDelegate OnPropBoolChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Property PropBool Changed")
	FTestbed1StructArrayInterfacePropBoolChangedDelegateBP OnPropBoolChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool)
	{
		OnPropBoolChanged.Broadcast(InPropBool);
		OnPropBoolChangedBP.Broadcast(InPropBool);
	}

	FTestbed1StructArrayInterfacePropIntChangedDelegate OnPropIntChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Property PropInt Changed")
	FTestbed1StructArrayInterfacePropIntChangedDelegateBP OnPropIntChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
		OnPropIntChangedBP.Broadcast(InPropInt);
	}

	FTestbed1StructArrayInterfacePropFloatChangedDelegate OnPropFloatChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTestbed1StructArrayInterfacePropFloatChangedDelegateBP OnPropFloatChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat)
	{
		OnPropFloatChanged.Broadcast(InPropFloat);
		OnPropFloatChangedBP.Broadcast(InPropFloat);
	}

	FTestbed1StructArrayInterfacePropStringChangedDelegate OnPropStringChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Property PropString Changed")
	FTestbed1StructArrayInterfacePropStringChangedDelegateBP OnPropStringChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString)
	{
		OnPropStringChanged.Broadcast(InPropString);
		OnPropStringChangedBP.Broadcast(InPropString);
	}

	FTestbed1StructArrayInterfacePropEnumChangedDelegate OnPropEnumChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Property PropEnum Changed")
	FTestbed1StructArrayInterfacePropEnumChangedDelegateBP OnPropEnumChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropEnumChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", DisplayName = "Broadcast Property PropEnum Changed")
	void BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum)
	{
		OnPropEnumChanged.Broadcast(InPropEnum);
		OnPropEnumChangedBP.Broadcast(InPropEnum);
	}
};

/**
 * Interface UTestbed1StructArrayInterface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed1StructArrayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructArrayInterface
 */
class TESTBED1API_API ITestbed1StructArrayInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual UTestbed1StructArrayInterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	virtual TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	virtual TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	virtual TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	virtual TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const TArray<ETestbed1Enum0>& ParamEnum) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	virtual TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual TArray<FTestbed1StructBool> GetPropBool() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual void SetPropBool(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual TArray<FTestbed1StructInt> GetPropInt() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual void SetPropInt(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual TArray<FTestbed1StructFloat> GetPropFloat() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual void SetPropFloat(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual TArray<FTestbed1StructString> GetPropString() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual void SetPropString(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual TArray<ETestbed1Enum0> GetPropEnum() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	virtual void SetPropEnum(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum) = 0;
};
