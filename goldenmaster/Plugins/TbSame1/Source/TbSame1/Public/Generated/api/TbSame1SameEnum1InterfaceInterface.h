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
#include "Engine/LatentActionManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceInterface.generated.h"

/**
 * Declaration for SameEnum1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceSig1Delegate, ETbSame1Enum1, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceProp1ChangedDelegate, ETbSame1Enum1, Prop1);

/**
 * Interface UTbSame1SameEnum1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame1SameEnum1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameEnum1InterfaceInterface
 */
class TBSAME1_API ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface")
	virtual FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface")
	virtual FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1);
	virtual ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 GetProp1() const;
	virtual ETbSame1Enum1 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void SetProp1(ETbSame1Enum1 InProp1);
	virtual void SetProp1_Implementation(ETbSame1Enum1 InProp1) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(ETbSame1Enum1 Param1);
	virtual void BroadcastSig1_Implementation(ETbSame1Enum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(ETbSame1Enum1 Prop1);
	virtual void BroadcastProp1Changed_Implementation(ETbSame1Enum1 Prop1) = 0;
};

/**
 * Abstract UAbstractTbSame1SameEnum1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME1_API UAbstractTbSame1SameEnum1Interface : public UGameInstanceSubsystem, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Sig1 Signal")
	FTbSame1SameEnum1InterfaceSig1Delegate Sig1Signal;
	virtual FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Prop1 Changed")
	FTbSame1SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::Func1Async_Implementation, return;);
	virtual ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::Func1_Implementation, return ETbSame1Enum1::TSE_VALUE1;);

	// properties
	virtual ETbSame1Enum1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::GetProp1_Implementation, return ETbSame1Enum1::TSE_VALUE1;);

	virtual void SetProp1_Implementation(ETbSame1Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::SetProp1_Implementation, return;);

protected:
	// signals
	virtual void BroadcastSig1_Implementation(ETbSame1Enum1 Param1) override;

	virtual void BroadcastProp1Changed_Implementation(ETbSame1Enum1 InProp1) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TSE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);
};