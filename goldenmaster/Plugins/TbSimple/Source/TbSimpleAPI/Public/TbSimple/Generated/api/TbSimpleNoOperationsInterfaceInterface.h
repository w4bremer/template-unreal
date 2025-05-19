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
#include "TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceInterface.generated.h"

/**
 * Declaration for NoOperationsInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE(FTbSimpleNoOperationsInterfaceSigVoidDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleNoOperationsInterfaceSigVoidDelegateBP);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceSigBoolDelegate, bool /* bParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceSigBoolDelegateBP, bool, bParamBool);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropBoolChangedDelegate, bool /* bPropBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropBoolChangedDelegateBP, bool, bPropBool);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropIntChangedDelegate, int32 /* PropInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropIntChangedDelegateBP, int32, PropInt);

/**
 * Class UTbSimpleNoOperationsInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleNoOperationsInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbSimpleNoOperationsInterfaceSigVoidDelegate OnSigVoidSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleNoOperationsInterfaceSigVoidDelegateBP OnSigVoidSignalBP;
	/// C++ wrapper for BP functions to safely call SigVoidSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast SigVoid Signal")
	void BroadcastSigVoidSignal()
	{
		OnSigVoidSignal.Broadcast();
		OnSigVoidSignalBP.Broadcast();
	}

	FTbSimpleNoOperationsInterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleNoOperationsInterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(bool bParamBool)
	{
		OnSigBoolSignal.Broadcast(bParamBool);
		OnSigBoolSignalBP.Broadcast(bParamBool);
	}

	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate OnPropBoolChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegateBP OnPropBoolChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
	{
		OnPropBoolChanged.Broadcast(bInPropBool);
		OnPropBoolChangedBP.Broadcast(bInPropBool);
	}

	FTbSimpleNoOperationsInterfacePropIntChangedDelegate OnPropIntChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleNoOperationsInterfacePropIntChangedDelegateBP OnPropIntChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
		OnPropIntChangedBP.Broadcast(InPropInt);
	}
};

/**
 * Interface UTbSimpleNoOperationsInterface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleNoOperationsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoOperationsInterface
 */
class TBSIMPLEAPI_API ITbSimpleNoOperationsInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	virtual UTbSimpleNoOperationsInterfaceSignals* _GetSignals() = 0;

	// methods

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	virtual bool GetPropBool() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	virtual void SetPropBool(UPARAM(DisplayName = "bPropBool") bool bInPropBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	virtual int32 GetPropInt() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	virtual void SetPropInt(UPARAM(DisplayName = "PropInt") int32 InPropInt) = 0;
};
