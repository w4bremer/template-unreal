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
#include "TbEnum_data.h"
#include "TbEnumEnumInterfaceInterface.generated.h"

/**
 * Declaration for EnumInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig0Delegate, ETbEnumEnum0 /* Param0 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig0DelegateBP, ETbEnumEnum0, Param0);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig1Delegate, ETbEnumEnum1 /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig1DelegateBP, ETbEnumEnum1, Param1);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig2Delegate, ETbEnumEnum2 /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig2DelegateBP, ETbEnumEnum2, Param2);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig3Delegate, ETbEnumEnum3 /* Param3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig3DelegateBP, ETbEnumEnum3, Param3);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp0ChangedDelegate, ETbEnumEnum0 /* Prop0 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp0ChangedDelegateBP, ETbEnumEnum0, Prop0);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp1ChangedDelegate, ETbEnumEnum1 /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp1ChangedDelegateBP, ETbEnumEnum1, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp2ChangedDelegate, ETbEnumEnum2 /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp2ChangedDelegateBP, ETbEnumEnum2, Prop2);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp3ChangedDelegate, ETbEnumEnum3 /* Prop3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp3ChangedDelegateBP, ETbEnumEnum3, Prop3);

/**
 * Class UTbEnumEnumInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBENUMAPI_API UTbEnumEnumInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbEnumEnumInterfaceSig0Delegate OnSig0Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Sig0 Signal")
	FTbEnumEnumInterfaceSig0DelegateBP OnSig0SignalBP;
	/// C++ wrapper for BP functions to safely call Sig0Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Sig0 Signal")
	void BroadcastSig0Signal(ETbEnumEnum0 Param0)
	{
		OnSig0Signal.Broadcast(Param0);
		OnSig0SignalBP.Broadcast(Param0);
	}

	FTbEnumEnumInterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Sig1 Signal")
	FTbEnumEnumInterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(ETbEnumEnum1 Param1)
	{
		OnSig1Signal.Broadcast(Param1);
		OnSig1SignalBP.Broadcast(Param1);
	}

	FTbEnumEnumInterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Sig2 Signal")
	FTbEnumEnumInterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(ETbEnumEnum2 Param2)
	{
		OnSig2Signal.Broadcast(Param2);
		OnSig2SignalBP.Broadcast(Param2);
	}

	FTbEnumEnumInterfaceSig3Delegate OnSig3Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Sig3 Signal")
	FTbEnumEnumInterfaceSig3DelegateBP OnSig3SignalBP;
	/// C++ wrapper for BP functions to safely call Sig3Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Sig3 Signal")
	void BroadcastSig3Signal(ETbEnumEnum3 Param3)
	{
		OnSig3Signal.Broadcast(Param3);
		OnSig3SignalBP.Broadcast(Param3);
	}

	FTbEnumEnumInterfaceProp0ChangedDelegate OnProp0Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Property Prop0 Changed")
	FTbEnumEnumInterfaceProp0ChangedDelegateBP OnProp0ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp0Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Property Prop0 Changed")
	void BroadcastProp0Changed(UPARAM(DisplayName = "Prop0") ETbEnumEnum0 InProp0)
	{
		OnProp0Changed.Broadcast(InProp0);
		OnProp0ChangedBP.Broadcast(InProp0);
	}

	FTbEnumEnumInterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Property Prop1 Changed")
	FTbEnumEnumInterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbEnumEnum1 InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
		OnProp1ChangedBP.Broadcast(InProp1);
	}

	FTbEnumEnumInterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Property Prop2 Changed")
	FTbEnumEnumInterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbEnumEnum2 InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
		OnProp2ChangedBP.Broadcast(InProp2);
	}

	FTbEnumEnumInterfaceProp3ChangedDelegate OnProp3Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Property Prop3 Changed")
	FTbEnumEnumInterfaceProp3ChangedDelegateBP OnProp3ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp3Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Signals", DisplayName = "Broadcast Property Prop3 Changed")
	void BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") ETbEnumEnum3 InProp3)
	{
		OnProp3Changed.Broadcast(InProp3);
		OnProp3ChangedBP.Broadcast(InProp3);
	}
};

/**
 * Interface UTbEnumEnumInterface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbEnumEnumInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbEnumEnumInterface
 */
class TBENUMAPI_API ITbEnumEnumInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	virtual UTbEnumEnumInterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	virtual ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	virtual ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	virtual ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	virtual ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual ETbEnumEnum0 GetProp0() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual void SetProp0(UPARAM(DisplayName = "Prop0") ETbEnumEnum0 InProp0) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual ETbEnumEnum1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") ETbEnumEnum1 InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual ETbEnumEnum2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") ETbEnumEnum2 InProp2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual ETbEnumEnum3 GetProp3() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	virtual void SetProp3(UPARAM(DisplayName = "Prop3") ETbEnumEnum3 InProp3) = 0;
};
