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
#include "TbRefInterfaces/Generated/api/TbRefInterfacesParentIfInterface.h"
#include "AbstractTbRefInterfacesParentIf.generated.h"

/**
 * Abstract UAbstractTbRefInterfacesParentIf
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBREFINTERFACESAPI_API UAbstractTbRefInterfacesParentIf : public UGameInstanceSubsystem, public ITbRefInterfacesParentIf
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbRefInterfacesParentIf();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbRefInterfacesParentIfSignals* _GetSignals() override;

	// methods
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Result, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override;
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::LocalIfMethod, return TScriptInterface<ITbRefInterfacesSimpleLocalIf>(););

	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesImportCounter>& Result, const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override;
	virtual TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::ImportedIfMethod, return TScriptInterface<ITbRefInterfacesImportCounter>(););

	// properties
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::GetLocalIf, return TScriptInterface<ITbRefInterfacesSimpleLocalIf>(););
	virtual void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf) override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::SetLocalIf, return;);

	virtual TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::GetImportedIf, return TScriptInterface<ITbRefInterfacesImportCounter>(););
	virtual void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf) override PURE_VIRTUAL(UAbstractTbRefInterfacesParentIf::SetImportedIf, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetLocalIf_Private, BlueprintSetter = SetLocalIf_Private, Category = "ApiGear|TbRefInterfaces|ParentIf")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIf{TScriptInterface<ITbRefInterfacesSimpleLocalIf>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetLocalIf_Private(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetImportedIf_Private, BlueprintSetter = SetImportedIf_Private, Category = "ApiGear|TbRefInterfaces|ParentIf")
	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIf{TScriptInterface<ITbRefInterfacesImportCounter>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetImportedIf_Private(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf);

private:
	// signals
	UPROPERTY()
	UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals;
};
