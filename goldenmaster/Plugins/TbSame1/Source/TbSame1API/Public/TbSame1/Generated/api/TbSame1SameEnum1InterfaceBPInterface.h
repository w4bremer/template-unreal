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
#include "TbSame1SameEnum1InterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceBPInterface.generated.h"

/**
 * Interface UTbSame1SameEnum1InterfaceBP only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame1SameEnum1InterfaceBP : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameEnum1InterfaceBP
 */
class TBSAME1API_API ITbSame1SameEnum1InterfaceBP
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	UTbSame1SameEnum1InterfaceSignals* _GetSignals();
	virtual UTbSame1SameEnum1InterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Operations")
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1);
	virtual ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties")
	ETbSame1Enum1 GetProp1() const;
	virtual ETbSame1Enum1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties")
	void SetProp1(ETbSame1Enum1 InProp1);
	virtual void SetProp1_Implementation(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1) = 0;
};
