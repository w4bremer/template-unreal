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
#include "TbSame2_data.h"
#include "TbSame2/Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "AbstractTbSame2SameEnum1Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameEnum1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2API_API UAbstractTbSame2SameEnum1Interface : public UGameInstanceSubsystem, public ITbSame2SameEnum1Interface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame2SameEnum1Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame2SameEnum1InterfaceSignals* _GetSignals() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	virtual ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum1Interface::Func1, return ETbSame2Enum1::TS2E1_VALUE1;);

	// properties
	virtual ETbSame2Enum1 GetProp1() const override PURE_VIRTUAL(UAbstractTbSame2SameEnum1Interface::GetProp1, return ETbSame2Enum1::TS2E1_VALUE1;);
	virtual void SetProp1(ETbSame2Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum1Interface::SetProp1, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum1Interface")
	ETbSame2Enum1 Prop1{ETbSame2Enum1::TS2E1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame2Enum1 InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals;
};
