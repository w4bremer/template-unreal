
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
#include "Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimpleSimpleArrayInterface.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleSimpleArrayInterface : public UObject, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleArrayInterface();

	// signals
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	TArray<bool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	TArray<float> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	TArray<FString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override{};
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override{};
	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override{};
	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override{};
	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;

protected:
	// signals
	void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) override;

	void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) override;

	void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) override;

	void BroadcastSigString_Implementation(const TArray<FString>& ParamString) override;

	void BroadcastPropBoolChanged_Implementation(const TArray<bool>& PropBool) override;

	void BroadcastPropIntChanged_Implementation(const TArray<int32>& PropInt) override;

	void BroadcastPropFloatChanged_Implementation(const TArray<float>& PropFloat) override;

	void BroadcastPropStringChanged_Implementation(const TArray<FString>& PropString) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	TArray<bool> PropBool{TArray<bool>()};
	TArray<int32> PropInt{TArray<int32>()};
	TArray<float> PropFloat{TArray<float>()};
	TArray<FString> PropString{TArray<FString>()};
};