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

#include "Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "apigearolink.h"
#include "Async/Async.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "Testbed1Settings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed1StructInterfacePropertiesData
{
	FTestbed1StructBool PropBool{FTestbed1StructBool()};
	FTestbed1StructInt PropInt{FTestbed1StructInt()};
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};
	FTestbed1StructString PropString{FTestbed1StructString()};
};
DEFINE_LOG_CATEGORY(LogTestbed1StructInterfaceOLinkClient);

UTestbed1StructInterfaceOLinkClient::UTestbed1StructInterfaceOLinkClient()
	: UAbstractTestbed1StructInterface()
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	, _SentData(MakeUnique<Testbed1StructInterfacePropertiesData>())
#else
	, _SentData(MakePimpl<Testbed1StructInterfacePropertiesData>())
#endif
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed1.StructInterface");
}

UTestbed1StructInterfaceOLinkClient::UTestbed1StructInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTestbed1StructInterfaceOLinkClient::~UTestbed1StructInterfaceOLinkClient() = default;

void UTestbed1StructInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{ _SubscriptionStatusChanged.Broadcast(true); });
	m_sink->setOnReleaseCallback([this]()
		{ _SubscriptionStatusChanged.Broadcast(false); });

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

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("No valid olink connection for the %s client, please set in the ApiGear Testbed1 plugin settings or during run time"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTestbed1StructInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();
	m_sink->resetOnInitCallback();
	m_sink->resetOnReleaseCallback();

	if (Connection.GetObject())
	{
		UUnrealOLink* UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTestbed1StructInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearOLinkProtocolIdentifier, TEXT("Cannot use connection - must be of type olink"));

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

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceOLinkClient::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

FTestbed1StructInt UTestbed1StructInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceOLinkClient::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

FTestbed1StructFloat UTestbed1StructInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceOLinkClient::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

FTestbed1StructString UTestbed1StructInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceOLinkClient::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<FTestbed1StructBool>());
				}
				else
				{
					UE_LOG(LogTestbed1StructInterfaceOLinkClient, Error, TEXT("FuncBool: OLink service returned empty value - should have returned type of FTestbed1StructBool"));
					Promise.SetValue(FTestbed1StructBool());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
			m_sink->GetNode()->invokeRemote(memberId, {ParamBool}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<FTestbed1StructBool>());
				}
				else
				{
					UE_LOG(LogTestbed1StructInterfaceOLinkClient, Error, TEXT("FuncInt: OLink service returned empty value - should have returned type of FTestbed1StructBool"));
					Promise.SetValue(FTestbed1StructBool());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt");
			m_sink->GetNode()->invokeRemote(memberId, {ParamInt}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructFloat UTestbed1StructInterfaceOLinkClient::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructFloat();
	}
	TPromise<FTestbed1StructFloat> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<FTestbed1StructFloat>());
				}
				else
				{
					UE_LOG(LogTestbed1StructInterfaceOLinkClient, Error, TEXT("FuncFloat: OLink service returned empty value - should have returned type of FTestbed1StructFloat"));
					Promise.SetValue(FTestbed1StructFloat());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat");
			m_sink->GetNode()->invokeRemote(memberId, {ParamFloat}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructString UTestbed1StructInterfaceOLinkClient::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FTestbed1StructString();
	}
	TPromise<FTestbed1StructString> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<FTestbed1StructString>());
				}
				else
				{
					UE_LOG(LogTestbed1StructInterfaceOLinkClient, Error, TEXT("FuncString: OLink service returned empty value - should have returned type of FTestbed1StructString"));
					Promise.SetValue(FTestbed1StructString());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString");
			m_sink->GetNode()->invokeRemote(memberId, {ParamString}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

bool UTestbed1StructInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTestbed1StructInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (PropBool != fields["propBool"].get<FTestbed1StructBool>());
	if (bPropBoolChanged)
	{
		PropBool = fields["propBool"].get<FTestbed1StructBool>();
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<FTestbed1StructInt>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<FTestbed1StructInt>();
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}

	const bool bPropFloatChanged = fields.contains("propFloat") && (PropFloat != fields["propFloat"].get<FTestbed1StructFloat>());
	if (bPropFloatChanged)
	{
		PropFloat = fields["propFloat"].get<FTestbed1StructFloat>();
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}

	const bool bPropStringChanged = fields.contains("propString") && (PropString != fields["propString"].get<FTestbed1StructString>());
	if (bPropStringChanged)
	{
		PropString = fields["propString"].get<FTestbed1StructString>();
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

void UTestbed1StructInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigBool")
	{
		const FTestbed1StructBool& ParamBool = args[0].get<FTestbed1StructBool>();
		Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(ParamBool);
		return;
	}

	if (signalName == "sigInt")
	{
		const FTestbed1StructInt& ParamInt = args[0].get<FTestbed1StructInt>();
		Execute__GetSignals(this)->OnSigIntSignal.Broadcast(ParamInt);
		return;
	}

	if (signalName == "sigFloat")
	{
		const FTestbed1StructFloat& ParamFloat = args[0].get<FTestbed1StructFloat>();
		Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(ParamFloat);
		return;
	}

	if (signalName == "sigString")
	{
		const FTestbed1StructString& ParamString = args[0].get<FTestbed1StructString>();
		Execute__GetSignals(this)->OnSigStringSignal.Broadcast(ParamString);
		return;
	}
}
