
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
#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesParentIf.h"
#include "TbRefInterfacesParentIf.generated.h"

UCLASS(BlueprintType)
class TBREFINTERFACESIMPLEMENTATION_API UTbRefInterfacesParentIfImplementation : public UAbstractTbRefInterfacesParentIf
{
	GENERATED_BODY()
public:
	virtual ~UTbRefInterfacesParentIfImplementation();

	// properties
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf) override;

	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	void _ResetProperties();

	// operations
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override;

	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override;
};
