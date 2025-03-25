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
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfacesSimpleLocalIfInterface.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImportCounterInterface.h"
#include "TbRefInterfaces_data.h"
#include "TbRefInterfacesParentIfInterface.generated.h"

/**
 * Declaration for ParentIf
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfLocalIfSignalDelegate, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfLocalIfSignalDelegateBP, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>&, Param);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfImportedIfSignalDelegate, const TScriptInterface<ITbRefInterfacesImportCounter>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfImportedIfSignalDelegateBP, const TScriptInterface<ITbRefInterfacesImportCounter>&, Param);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfLocalIfChangedDelegate, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& /* LocalIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfLocalIfChangedDelegateBP, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>&, LocalIf);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfImportedIfChangedDelegate, const TScriptInterface<ITbRefInterfacesImportCounter>& /* ImportedIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfImportedIfChangedDelegateBP, const TScriptInterface<ITbRefInterfacesImportCounter>&, ImportedIf);

/**
 * Class UTbRefInterfacesParentIfSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBREFINTERFACESAPI_API UTbRefInterfacesParentIfSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbRefInterfacesParentIfLocalIfSignalDelegate OnLocalIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "LocalIfSignal Signal")
	FTbRefInterfacesParentIfLocalIfSignalDelegateBP OnLocalIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call LocalIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Broadcast LocalIfSignal Signal")
	void BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
	{
		OnLocalIfSignalSignal.Broadcast(Param);
		OnLocalIfSignalSignalBP.Broadcast(Param);
	}

	FTbRefInterfacesParentIfImportedIfSignalDelegate OnImportedIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "ImportedIfSignal Signal")
	FTbRefInterfacesParentIfImportedIfSignalDelegateBP OnImportedIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call ImportedIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Broadcast ImportedIfSignal Signal")
	void BroadcastImportedIfSignalSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
	{
		OnImportedIfSignalSignal.Broadcast(Param);
		OnImportedIfSignalSignalBP.Broadcast(Param);
	}

	FTbRefInterfacesParentIfLocalIfChangedDelegate OnLocalIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Property LocalIf Changed")
	FTbRefInterfacesParentIfLocalIfChangedDelegateBP OnLocalIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnLocalIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Broadcast Property LocalIf Changed")
	void BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
	{
		OnLocalIfChanged.Broadcast(InLocalIf);
		OnLocalIfChangedBP.Broadcast(InLocalIf);
	}

	FTbRefInterfacesParentIfImportedIfChangedDelegate OnImportedIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Property ImportedIf Changed")
	FTbRefInterfacesParentIfImportedIfChangedDelegateBP OnImportedIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnImportedIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Signals", DisplayName = "Broadcast Property ImportedIf Changed")
	void BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
	{
		OnImportedIfChanged.Broadcast(InImportedIf);
		OnImportedIfChangedBP.Broadcast(InImportedIf);
	}
};

/**
 * Interface UTbRefInterfacesParentIf only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefInterfacesParentIf : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefInterfacesParentIf
 */
class TBREFINTERFACESAPI_API ITbRefInterfacesParentIf
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	virtual UTbRefInterfacesParentIfSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Result, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesImportCounter>& Result, const TScriptInterface<ITbRefInterfacesImportCounter>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	virtual void SetLocalIf(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Properties")
	virtual void SetImportedIf(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf) = 0;
};
