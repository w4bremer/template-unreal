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
#include "TbRefInterfacesParentIfInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbRefInterfaces_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesParentIfBPInterface.generated.h"

/**
 * Interface UTbRefInterfacesParentIfBP only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbRefInterfacesParentIfBP : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefInterfacesParentIfBP
 */
class TBREFINTERFACESAPI_API ITbRefInterfacesParentIfBP
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	UTbRefInterfacesParentIfSignals* _GetSignals();
	virtual UTbRefInterfacesParentIfSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Result, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);
	virtual void LocalIfMethodAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Result, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod_Implementation(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesImportCounter>& Result, const TScriptInterface<ITbRefInterfacesImportCounter>& Param);
	virtual void ImportedIfMethodAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesImportCounter>& Result, const TScriptInterface<ITbRefInterfacesImportCounter>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations")
	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);
	virtual TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod_Implementation(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const;
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf);
	virtual void SetLocalIf_Implementation(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const;
	virtual TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf);
	virtual void SetImportedIf_Implementation(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf) = 0;
};
