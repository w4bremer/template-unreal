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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

UTbSimpleSimpleInterfaceOLinkClient::UTbSimpleSimpleInterfaceOLinkClient()
	: ITbSimpleSimpleInterfaceInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.simple.SimpleInterface");
}

void UTbSimpleSimpleInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->node()->registry().addSink(m_sink);
		AGCM->GetOLinkConnection()->linkObjectSource(m_sink->olinkObjectName());
	}

	FUnrealOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FUnrealOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);
}

void UTbSimpleSimpleInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(m_sink->olinkObjectName());
		AGCM->GetOLinkConnection()->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

FTbSimpleSimpleInterfaceSigVoidDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigInt32_Implementation(int32 ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
}

FTbSimpleSimpleInterfaceSigInt32Delegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigInt64_Implementation(int64 ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
}

FTbSimpleSimpleInterfaceSigInt64Delegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigFloat32_Implementation(float ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
}

FTbSimpleSimpleInterfaceSigFloat32Delegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigFloat64_Implementation(double ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
}

FTbSimpleSimpleInterfaceSigFloat64Delegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	bPropBool = bInPropBool;
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleSimpleInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropBool_Implementation(bool bInPropBool)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool"), bInPropBool);
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleSimpleInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropInt_Implementation(int32 InPropInt)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt"), InPropInt);
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropInt32Changed_Implementation(int32 InPropInt32)
{
	PropInt32 = InPropInt32;
	PropInt32Changed.Broadcast(InPropInt32);
}

int32 UTbSimpleSimpleInterfaceOLinkClient::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropInt32_Implementation(int32 InPropInt32)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt32"), InPropInt32);
}

FTbSimpleSimpleInterfacePropInt32ChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropInt64Changed_Implementation(int64 InPropInt64)
{
	PropInt64 = InPropInt64;
	PropInt64Changed.Broadcast(InPropInt64);
}

int64 UTbSimpleSimpleInterfaceOLinkClient::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropInt64_Implementation(int64 InPropInt64)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt64"), InPropInt64);
}

FTbSimpleSimpleInterfacePropInt64ChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

float UTbSimpleSimpleInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropFloat_Implementation(float InPropFloat)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat"), InPropFloat);
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropFloat32Changed_Implementation(float InPropFloat32)
{
	PropFloat32 = InPropFloat32;
	PropFloat32Changed.Broadcast(InPropFloat32);
}

float UTbSimpleSimpleInterfaceOLinkClient::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropFloat32_Implementation(float InPropFloat32)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat32"), InPropFloat32);
}

FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropFloat64Changed_Implementation(double InPropFloat64)
{
	PropFloat64 = InPropFloat64;
	PropFloat64Changed.Broadcast(InPropFloat64);
}

double UTbSimpleSimpleInterfaceOLinkClient::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropFloat64_Implementation(double InPropFloat64)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat64"), InPropFloat64);
}

FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
}

void UTbSimpleSimpleInterfaceOLinkClient::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

FString UTbSimpleSimpleInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterfaceOLinkClient::SetPropString_Implementation(const FString& InPropString)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString"), InPropString);
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceOLinkClient::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleInterfaceOLinkClient::FuncVoid_Implementation()
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcVoid"), {}, GetSimpleInterfaceStateFunc);
}

bool UTbSimpleSimpleInterfaceOLinkClient::FuncBool_Implementation(bool bParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return false;
	}
	TPromise<bool> Promise;
	Async(EAsyncExecution::Thread,
		[bParamBool, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<bool>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool"), {bParamBool}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTbSimpleSimpleInterfaceOLinkClient::FuncInt_Implementation(int32 ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt"), {ParamInt}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTbSimpleSimpleInterfaceOLinkClient::FuncInt32_Implementation(int32 ParamInt32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt32, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt32"), {ParamInt32}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int64 UTbSimpleSimpleInterfaceOLinkClient::FuncInt64_Implementation(int64 ParamInt64)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0LL;
	}
	TPromise<int64> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt64, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int64>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt64"), {ParamInt64}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

float UTbSimpleSimpleInterfaceOLinkClient::FuncFloat_Implementation(float ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0.0f;
	}
	TPromise<float> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<float>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat"), {ParamFloat}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

float UTbSimpleSimpleInterfaceOLinkClient::FuncFloat32_Implementation(float ParamFloat32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0.0f;
	}
	TPromise<float> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat32, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<float>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat32"), {ParamFloat32}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

double UTbSimpleSimpleInterfaceOLinkClient::FuncFloat64_Implementation(double ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0.0;
	}
	TPromise<double> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<double>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat64"), {ParamFloat}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FString UTbSimpleSimpleInterfaceOLinkClient::FuncString_Implementation(const FString& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FString();
	}
	TPromise<FString> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FString>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString"), {ParamString}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (bPropBool != fields["propBool"].get<bool>())
		{
			bPropBool = fields["propBool"].get<bool>();
			Execute_BroadcastPropBoolChanged(this, bPropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<int32>())
		{
			PropInt = fields["propInt"].get<int32>();
			Execute_BroadcastPropIntChanged(this, PropInt);
		}
	}
	if (fields.contains("propInt32"))
	{
		if (PropInt32 != fields["propInt32"].get<int32>())
		{
			PropInt32 = fields["propInt32"].get<int32>();
			Execute_BroadcastPropInt32Changed(this, PropInt32);
		}
	}
	if (fields.contains("propInt64"))
	{
		if (PropInt64 != fields["propInt64"].get<int64>())
		{
			PropInt64 = fields["propInt64"].get<int64>();
			Execute_BroadcastPropInt64Changed(this, PropInt64);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<float>())
		{
			PropFloat = fields["propFloat"].get<float>();
			Execute_BroadcastPropFloatChanged(this, PropFloat);
		}
	}
	if (fields.contains("propFloat32"))
	{
		if (PropFloat32 != fields["propFloat32"].get<float>())
		{
			PropFloat32 = fields["propFloat32"].get<float>();
			Execute_BroadcastPropFloat32Changed(this, PropFloat32);
		}
	}
	if (fields.contains("propFloat64"))
	{
		if (PropFloat64 != fields["propFloat64"].get<double>())
		{
			PropFloat64 = fields["propFloat64"].get<double>();
			Execute_BroadcastPropFloat64Changed(this, PropFloat64);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<FString>())
		{
			PropString = fields["propString"].get<FString>();
			Execute_BroadcastPropStringChanged(this, PropString);
		}
	}
}

void UTbSimpleSimpleInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigVoid")
	{
		Execute_BroadcastSigVoid(this);
		return;
	}
	if (signalName == "sigBool")
	{
		Execute_BroadcastSigBool(this, args[0].get<bool>());
		return;
	}
	if (signalName == "sigInt")
	{
		Execute_BroadcastSigInt(this, args[0].get<int32>());
		return;
	}
	if (signalName == "sigInt32")
	{
		Execute_BroadcastSigInt32(this, args[0].get<int32>());
		return;
	}
	if (signalName == "sigInt64")
	{
		Execute_BroadcastSigInt64(this, args[0].get<int64>());
		return;
	}
	if (signalName == "sigFloat")
	{
		Execute_BroadcastSigFloat(this, args[0].get<float>());
		return;
	}
	if (signalName == "sigFloat32")
	{
		Execute_BroadcastSigFloat32(this, args[0].get<float>());
		return;
	}
	if (signalName == "sigFloat64")
	{
		Execute_BroadcastSigFloat64(this, args[0].get<double>());
		return;
	}
	if (signalName == "sigString")
	{
		Execute_BroadcastSigString(this, args[0].get<FString>());
		return;
	}
}