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

#include "TbSimpleSimpleArrayInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimpleSimpleArrayInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceOLinkClient : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceOLinkClient();
	virtual ~UTbSimpleSimpleArrayInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigInt32Delegate SigInt32Signal;
	FTbSimpleSimpleArrayInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigInt64Delegate SigInt64Signal;
	FTbSimpleSimpleArrayInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigFloat32Delegate SigFloat32Signal;
	FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigFloat64Delegate SigFloat64Signal;
	FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate PropInt32Changed;
	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate PropInt64Changed;
	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate PropFloat32Changed;
	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate PropFloat64Changed;
	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	TArray<bool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override{};
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override{};
	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override{};
	TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override;

	void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override{};
	TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override{};
	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override{};
	TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override;

	void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override{};
	TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override{};
	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;

protected:
	// signals
	void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) override;

	void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) override;

	void BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32) override;

	void BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64) override;

	void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) override;

	void BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32) override;

	void BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64) override;

	void BroadcastSigString_Implementation(const TArray<FString>& ParamString) override;

	void BroadcastPropBoolChanged_Implementation(const TArray<bool>& PropBool) override;

	void BroadcastPropIntChanged_Implementation(const TArray<int32>& PropInt) override;

	void BroadcastPropInt32Changed_Implementation(const TArray<int32>& PropInt32) override;

	void BroadcastPropInt64Changed_Implementation(const TArray<int64>& PropInt64) override;

	void BroadcastPropFloatChanged_Implementation(const TArray<float>& PropFloat) override;

	void BroadcastPropFloat32Changed_Implementation(const TArray<float>& PropFloat32) override;

	void BroadcastPropFloat64Changed_Implementation(const TArray<double>& PropFloat64) override;

	void BroadcastPropStringChanged_Implementation(const TArray<FString>& PropString) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
	TArray<bool> PropBool{TArray<bool>()};
	TArray<int32> PropInt{TArray<int32>()};
	TArray<int32> PropInt32{TArray<int32>()};
	TArray<int64> PropInt64{TArray<int64>()};
	TArray<float> PropFloat{TArray<float>()};
	TArray<float> PropFloat32{TArray<float>()};
	TArray<double> PropFloat64{TArray<double>()};
	TArray<FString> PropString{TArray<FString>()};
};