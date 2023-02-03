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

#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "Async/Async.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
#include "Testbed1Settings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed1StructArrayInterfacePropertiesData
{
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};
};
DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceOLinkClient);

UTestbed1StructArrayInterfaceOLinkClient::UTestbed1StructArrayInterfaceOLinkClient()
	: UAbstractTestbed1StructArrayInterface()
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	, _SentData(MakeUnique<Testbed1StructArrayInterfacePropertiesData>())
#else
	, _SentData(MakePimpl<Testbed1StructArrayInterfacePropertiesData>())
#endif
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed1.StructArrayInterface");
}

UTestbed1StructArrayInterfaceOLinkClient::UTestbed1StructArrayInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTestbed1StructArrayInterfaceOLinkClient::~UTestbed1StructArrayInterfaceOLinkClient() = default;

void UTestbed1StructArrayInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

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

	check(GEngine);
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->ConnectionIdentifier);

	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTestbed1StructArrayInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (Connection.GetObject())
	{
		UUnrealOLink* UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTestbed1StructArrayInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == "olink", TEXT("Cannot use connection - must be of type olink"));

	UUnrealOLink* UnrealOLinkConnection = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
		UnrealOLinkConnection = nullptr;
	}

	// set up new connection
	UnrealOLinkConnection = Cast<UUnrealOLink>(InConnection.GetObject());
	UnrealOLinkConnection->node()->registry().addSink(m_sink);
	UnrealOLinkConnection->linkObjectSource(m_sink->olinkObjectName());

	Connection = InConnection;
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool_Implementation() == InPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropBool == InPropBool)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropBool);
	_SentData->PropBool = InPropBool;
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt_Implementation() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt == InPropInt)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt);
	_SentData->PropInt = InPropInt;
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat_Implementation() == InPropFloat)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropFloat == InPropFloat)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropFloat);
	_SentData->PropFloat = InPropFloat;
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropString_Implementation() == InPropString)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropString == InPropString)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropString);
	_SentData->PropString = InPropString;
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
			m_sink->GetNode()->invokeRemote(memberId, {ParamBool}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt");
			m_sink->GetNode()->invokeRemote(memberId, {ParamInt}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat");
			m_sink->GetNode()->invokeRemote(memberId, {ParamFloat}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString");
			m_sink->GetNode()->invokeRemote(memberId, {ParamString}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (PropBool != fields["propBool"].get<TArray<FTestbed1StructBool>>());
	if (bPropBoolChanged)
	{
		PropBool = fields["propBool"].get<TArray<FTestbed1StructBool>>();
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
		Execute_BroadcastPropIntChanged(this, PropInt);
	}

	const bool bPropFloatChanged = fields.contains("propFloat") && (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>());
	if (bPropFloatChanged)
	{
		PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}

	const bool bPropStringChanged = fields.contains("propString") && (PropString != fields["propString"].get<TArray<FTestbed1StructString>>());
	if (bPropStringChanged)
	{
		PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

void UTestbed1StructArrayInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigBool")
	{
		const TArray<FTestbed1StructBool>& ParamBool = args[0].get<TArray<FTestbed1StructBool>>();
		Execute_BroadcastSigBool(this, ParamBool);
		return;
	}

	if (signalName == "sigInt")
	{
		const TArray<FTestbed1StructInt>& ParamInt = args[0].get<TArray<FTestbed1StructInt>>();
		Execute_BroadcastSigInt(this, ParamInt);
		return;
	}

	if (signalName == "sigFloat")
	{
		const TArray<FTestbed1StructFloat>& ParamFloat = args[0].get<TArray<FTestbed1StructFloat>>();
		Execute_BroadcastSigFloat(this, ParamFloat);
		return;
	}

	if (signalName == "sigString")
	{
		const TArray<FTestbed1StructString>& ParamString = args[0].get<TArray<FTestbed1StructString>>();
		Execute_BroadcastSigString(this, ParamString);
		return;
	}
}
