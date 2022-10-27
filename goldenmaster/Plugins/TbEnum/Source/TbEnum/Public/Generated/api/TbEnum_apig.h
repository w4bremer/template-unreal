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

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "TbEnum_data.h"
#include "TbEnum_apig.generated.h"

/**
 * Declaration for EnumInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig0Delegate, const ETbEnumEnum0&, Param0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig1Delegate, const ETbEnumEnum1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig2Delegate, const ETbEnumEnum2&, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig3Delegate, const ETbEnumEnum3&, Param3);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp0ChangedDelegate, const ETbEnumEnum0&, Prop0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp1ChangedDelegate, const ETbEnumEnum1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp2ChangedDelegate, const ETbEnumEnum2&, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp3ChangedDelegate, const ETbEnumEnum3&, Prop3);

/**
 * Interface UTbEnumEnumInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbEnumEnumInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbEnumEnumInterfaceInterface
 */
class TBENUM_API ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0);
	virtual void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Func0(const ETbEnumEnum0& Param0);
	virtual ETbEnumEnum0 Func0_Implementation(const ETbEnumEnum0& Param0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Func1(const ETbEnumEnum1& Param1);
	virtual ETbEnumEnum1 Func1_Implementation(const ETbEnumEnum1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Func2(const ETbEnumEnum2& Param2);
	virtual ETbEnumEnum2 Func2_Implementation(const ETbEnumEnum2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Func3(const ETbEnumEnum3& Param3);
	virtual ETbEnumEnum3 Func3_Implementation(const ETbEnumEnum3& Param3) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 GetProp0() const;
	virtual ETbEnumEnum0 GetProp0_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp0(const ETbEnumEnum0& Prop0);
	virtual void SetProp0_Implementation(const ETbEnumEnum0& Prop0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 GetProp1() const;
	virtual ETbEnumEnum1 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp1(const ETbEnumEnum1& Prop1);
	virtual void SetProp1_Implementation(const ETbEnumEnum1& Prop1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 GetProp2() const;
	virtual ETbEnumEnum2 GetProp2_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp2(const ETbEnumEnum2& Prop2);
	virtual void SetProp2_Implementation(const ETbEnumEnum2& Prop2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 GetProp3() const;
	virtual ETbEnumEnum3 GetProp3_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp3(const ETbEnumEnum3& Prop3);
	virtual void SetProp3_Implementation(const ETbEnumEnum3& Prop3) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastSig0(const ETbEnumEnum0& Param0);
	virtual void BroadcastSig0_Implementation(const ETbEnumEnum0& Param0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastSig1(const ETbEnumEnum1& Param1);
	virtual void BroadcastSig1_Implementation(const ETbEnumEnum1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastSig2(const ETbEnumEnum2& Param2);
	virtual void BroadcastSig2_Implementation(const ETbEnumEnum2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastSig3(const ETbEnumEnum3& Param3);
	virtual void BroadcastSig3_Implementation(const ETbEnumEnum3& Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastProp0Changed(const ETbEnumEnum0& Prop0);
	virtual void BroadcastProp0Changed_Implementation(const ETbEnumEnum0& Prop0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastProp1Changed(const ETbEnumEnum1& Prop1);
	virtual void BroadcastProp1Changed_Implementation(const ETbEnumEnum1& Prop1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastProp2Changed(const ETbEnumEnum2& Prop2);
	virtual void BroadcastProp2Changed_Implementation(const ETbEnumEnum2& Prop2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void BroadcastProp3Changed(const ETbEnumEnum3& Prop3);
	virtual void BroadcastProp3Changed_Implementation(const ETbEnumEnum3& Prop3) = 0;
};