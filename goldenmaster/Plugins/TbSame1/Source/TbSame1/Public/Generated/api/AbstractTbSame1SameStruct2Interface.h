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
#include "TbSame1_data.h"
#include "TbSame1SameStruct2InterfaceInterface.h"
#include "AbstractTbSame1SameStruct2Interface.generated.h"

/**
 * Abstract UAbstractTbSame1SameStruct2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME1_API UAbstractTbSame1SameStruct2Interface : public UGameInstanceSubsystem, public ITbSame1SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Sig1 Signal")
	FTbSame1SameStruct2InterfaceSig1Delegate Sig1Signal;
	virtual FTbSame1SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Sig2 Signal")
	FTbSame1SameStruct2InterfaceSig2Delegate Sig2Signal;
	virtual FTbSame1SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Prop1 Changed")
	FTbSame1SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbSame1SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Prop2 Changed")
	FTbSame1SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	virtual FTbSame1SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;
	virtual FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::Func1_Implementation, return FTbSame1Struct1(););

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
	virtual FTbSame1Struct1 Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::Func2_Implementation, return FTbSame1Struct1(););

	// properties
	virtual FTbSame1Struct2 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::GetProp1_Implementation, return FTbSame1Struct2(););
	virtual void SetProp1_Implementation(const FTbSame1Struct2& InProp1) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::SetProp1_Implementation, return;);

	virtual FTbSame1Struct2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::GetProp2_Implementation, return FTbSame1Struct2(););
	virtual void SetProp2_Implementation(const FTbSame1Struct2& InProp2) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::SetProp2_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(const FTbSame1Struct1& Param1) override;

	virtual void BroadcastSig2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

	virtual void BroadcastProp1Changed_Implementation(const FTbSame1Struct2& InProp1) override;

	virtual void BroadcastProp2Changed_Implementation(const FTbSame1Struct2& InProp2) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop1{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame1Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop2{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame1Struct2& InProp2);
};
