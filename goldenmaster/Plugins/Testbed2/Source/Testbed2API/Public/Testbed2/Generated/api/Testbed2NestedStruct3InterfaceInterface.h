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
#include "Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceInterface.generated.h"

/**
 * Declaration for NestedStruct3Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1Delegate, const FTestbed2NestedStruct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1DelegateBP, const FTestbed2NestedStruct1&, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2Delegate, const FTestbed2NestedStruct1& /* Param1 */, const FTestbed2NestedStruct2& /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2DelegateBP, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

DECLARE_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3Delegate, const FTestbed2NestedStruct1& /* Param1 */, const FTestbed2NestedStruct2& /* Param2 */, const FTestbed2NestedStruct3& /* Param3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3DelegateBP, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2, const FTestbed2NestedStruct3&, Param3);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegateBP, const FTestbed2NestedStruct1&, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2& /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegateBP, const FTestbed2NestedStruct2&, Prop2);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegate, const FTestbed2NestedStruct3& /* Prop3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegateBP, const FTestbed2NestedStruct3&, Prop3);

/**
 * Class UTestbed2NestedStruct3InterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2API_API UTestbed2NestedStruct3InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTestbed2NestedStruct3InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct3InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
		OnSig1SignalBP.Broadcast(Param1);
	}

	FTestbed2NestedStruct3InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct3InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
	{
		OnSig2Signal.Broadcast(Param1, Param2);
		OnSig2SignalBP.Broadcast(Param1, Param2);
	}

	FTestbed2NestedStruct3InterfaceSig3Delegate OnSig3Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig3 Signal")
	FTestbed2NestedStruct3InterfaceSig3DelegateBP OnSig3SignalBP;
	/// C++ wrapper for BP functions to safely call Sig3Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig3 Signal")
	void BroadcastSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
	{
		OnSig3Signal.Broadcast(Param1, Param2, Param3);
		OnSig3SignalBP.Broadcast(Param1, Param2, Param3);
	}

	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
		OnProp1ChangedBP.Broadcast(InProp1);
	}

	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
		OnProp2ChangedBP.Broadcast(InProp2);
	}

	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate OnProp3Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop3 Changed")
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegateBP OnProp3ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp3Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop3 Changed")
	void BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3)
	{
		OnProp3Changed.Broadcast(InProp3);
		OnProp3ChangedBP.Broadcast(InProp3);
	}
};

/**
 * Interface UTestbed2NestedStruct3Interface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2NestedStruct3Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct3Interface
 */
class TESTBED2API_API ITestbed2NestedStruct3Interface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual UTestbed2NestedStruct3InterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct3 GetProp3() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp3(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3) = 0;
};
