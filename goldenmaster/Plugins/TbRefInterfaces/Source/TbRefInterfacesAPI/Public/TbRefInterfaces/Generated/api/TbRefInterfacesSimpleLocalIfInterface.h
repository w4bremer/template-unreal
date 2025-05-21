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
#include "TbRefInterfaces_data.h"
#include "TbRefInterfacesSimpleLocalIfInterface.generated.h"

/**
 * Declaration for SimpleLocalIf
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfIntSignalDelegate, int32 /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfIntSignalDelegateBP, int32, Param);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfIntPropertyChangedDelegate, int32 /* IntProperty */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfIntPropertyChangedDelegateBP, int32, IntProperty);

/**
 * Class UTbRefInterfacesSimpleLocalIfSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBREFINTERFACESAPI_API UTbRefInterfacesSimpleLocalIfSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbRefInterfacesSimpleLocalIfIntSignalDelegate OnIntSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "IntSignal Signal")
	FTbRefInterfacesSimpleLocalIfIntSignalDelegateBP OnIntSignalSignalBP;
	/// C++ wrapper for BP functions to safely call IntSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "Broadcast IntSignal Signal")
	void BroadcastIntSignalSignal(int32 Param)
	{
		OnIntSignalSignal.Broadcast(Param);
		OnIntSignalSignalBP.Broadcast(Param);
	}

	FTbRefInterfacesSimpleLocalIfIntPropertyChangedDelegate OnIntPropertyChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "Property IntProperty Changed")
	FTbRefInterfacesSimpleLocalIfIntPropertyChangedDelegateBP OnIntPropertyChangedBP;
	/// C++ wrapper for BP functions to safely call OnIntPropertyChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Signals", DisplayName = "Broadcast Property IntProperty Changed")
	void BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty)
	{
		OnIntPropertyChanged.Broadcast(InIntProperty);
		OnIntPropertyChangedBP.Broadcast(InIntProperty);
	}
};

/**
 * Interface UTbRefInterfacesSimpleLocalIf only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefInterfacesSimpleLocalIf : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefInterfacesSimpleLocalIf
 */
class TBREFINTERFACESAPI_API ITbRefInterfacesSimpleLocalIf
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	virtual UTbRefInterfacesSimpleLocalIfSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Operations")
	virtual int32 IntMethod(int32 Param) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Properties")
	virtual int32 GetIntProperty() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Properties")
	virtual void SetIntProperty(UPARAM(DisplayName = "IntProperty") int32 InIntProperty) = 0;
};
