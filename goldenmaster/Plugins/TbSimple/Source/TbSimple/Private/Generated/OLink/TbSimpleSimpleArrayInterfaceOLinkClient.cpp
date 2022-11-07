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

#include "TbSimpleSimpleArrayInterfaceOLinkClient.h"
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

UTbSimpleSimpleArrayInterfaceOLinkClient::UTbSimpleSimpleArrayInterfaceOLinkClient()
	: ITbSimpleSimpleArrayInterfaceInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.simple.SimpleArrayInterface");
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTbSimpleSimpleArrayInterfaceOLinkClient::Deinitialize()
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

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastSigBool_Implementation(const TArray<bool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastSigInt_Implementation(const TArray<int32>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastSigString_Implementation(const TArray<FString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool)
{
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool"), InPropBool);
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt"), InPropInt);
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat"), InPropFloat);
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString"), InPropString);
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return TArray<bool>();
	}
	TPromise<TArray<bool>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<bool>>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool"), {ParamBool}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return TArray<int32>();
	}
	TPromise<TArray<int32>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<int32>>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt"), {ParamInt}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return TArray<float>();
	}
	TPromise<TArray<float>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<float>>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat"), {ParamFloat}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<FString> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncString_Implementation(const TArray<FString>& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return TArray<FString>();
	}
	TPromise<TArray<FString>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<FString>>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString"), {ParamString}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (PropBool != fields["propBool"].get<TArray<bool>>())
		{
			PropBool = fields["propBool"].get<TArray<bool>>();
			Execute_BroadcastPropBoolChanged(this, PropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<TArray<int32>>())
		{
			PropInt = fields["propInt"].get<TArray<int32>>();
			Execute_BroadcastPropIntChanged(this, PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<TArray<float>>())
		{
			PropFloat = fields["propFloat"].get<TArray<float>>();
			Execute_BroadcastPropFloatChanged(this, PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<TArray<FString>>())
		{
			PropString = fields["propString"].get<TArray<FString>>();
			Execute_BroadcastPropStringChanged(this, PropString);
		}
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::emitSignal(const std::string& signalId, const nlohmann::json& args)
{
	std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (MemberName == "sigBool")
	{
		Execute_BroadcastSigBool(this, args[0].get<TArray<bool>>());
		return;
	}
	if (MemberName == "sigInt")
	{
		Execute_BroadcastSigInt(this, args[0].get<TArray<int32>>());
		return;
	}
	if (MemberName == "sigFloat")
	{
		Execute_BroadcastSigFloat(this, args[0].get<TArray<float>>());
		return;
	}
	if (MemberName == "sigString")
	{
		Execute_BroadcastSigString(this, args[0].get<TArray<FString>>());
		return;
	}
}
