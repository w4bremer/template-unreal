
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

#include "CoreMinimal.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameEnum2Interface.h"
#include "TbSame2SameEnum2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameEnum2InterfaceImplementation : public UAbstractTbSame2SameEnum2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameEnum2InterfaceImplementation();

	// properties
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(ETbSame2Enum1 Prop1) override;

	ETbSame2Enum2 GetProp2() const override;
	void SetProp2(ETbSame2Enum2 Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void _ResetProperties();

	// operations
	ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override;

	ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
};
