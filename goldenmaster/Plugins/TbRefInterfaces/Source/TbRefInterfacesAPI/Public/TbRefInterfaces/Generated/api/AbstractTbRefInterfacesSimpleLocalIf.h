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
#include "TbRefInterfaces_data.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfacesSimpleLocalIfInterface.h"
#include "AbstractTbRefInterfacesSimpleLocalIf.generated.h"

/**
 * Abstract UAbstractTbRefInterfacesSimpleLocalIf
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBREFINTERFACESAPI_API UAbstractTbRefInterfacesSimpleLocalIf : public UGameInstanceSubsystem, public ITbRefInterfacesSimpleLocalIf
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbRefInterfacesSimpleLocalIf();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbRefInterfacesSimpleLocalIfSignals* _GetSignals() override;

	// methods
	virtual void IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param) override;
	virtual int32 IntMethod(int32 Param) override PURE_VIRTUAL(UAbstractTbRefInterfacesSimpleLocalIf::IntMethod, return 0;);

	// properties
	virtual int32 GetIntProperty() const override PURE_VIRTUAL(UAbstractTbRefInterfacesSimpleLocalIf::GetIntProperty, return 0;);
	virtual void SetIntProperty(int32 InIntProperty) override PURE_VIRTUAL(UAbstractTbRefInterfacesSimpleLocalIf::SetIntProperty, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetIntProperty_Private, BlueprintSetter = SetIntProperty_Private, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	int32 IntProperty{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Properties", BlueprintInternalUseOnly)
	int32 GetIntProperty_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Properties", BlueprintInternalUseOnly)
	void SetIntProperty_Private(int32 InIntProperty);

private:
	// signals
	UPROPERTY()
	UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals;
};
