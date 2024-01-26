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

#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "apigearolink.h"
#include "Async/Async.h"
#include "Generated/api/TbEnum.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "TbEnumSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbEnumEnumInterfacePropertiesData
{
	std::atomic<ETbEnumEnum0> Prop0{ETbEnumEnum0::TEE_VALUE0};
	std::atomic<ETbEnumEnum1> Prop1{ETbEnumEnum1::TEE_VALUE1};
	std::atomic<ETbEnumEnum2> Prop2{ETbEnumEnum2::TEE_VALUE2};
	std::atomic<ETbEnumEnum3> Prop3{ETbEnumEnum3::TEE_VALUE3};
};
DEFINE_LOG_CATEGORY(LogTbEnumEnumInterfaceOLinkClient);

UTbEnumEnumInterfaceOLinkClient::UTbEnumEnumInterfaceOLinkClient()
	: UAbstractTbEnumEnumInterface()
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	, _SentData(MakeUnique<TbEnumEnumInterfacePropertiesData>())
#else
	, _SentData(MakePimpl<TbEnumEnumInterfacePropertiesData>())
#endif
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.enum.EnumInterface");
}

UTbEnumEnumInterfaceOLinkClient::UTbEnumEnumInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbEnumEnumInterfaceOLinkClient::~UTbEnumEnumInterfaceOLinkClient() = default;

void UTbEnumEnumInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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
	UTbEnumSettings* settings = GetMutableDefault<UTbEnumSettings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("No valid olink connection for the %s client, please set in the ApiGear TbEnum plugin settings or during run time"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbEnumEnumInterfaceOLinkClient::Deinitialize()
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

void UTbEnumEnumInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
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

ETbEnumEnum0 UTbEnumEnumInterfaceOLinkClient::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp0_Implementation(ETbEnumEnum0 InProp0)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp0_Implementation() == InProp0)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop0 == InProp0)
	{
		return;
	}	
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop0");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp0);	
	_SentData->Prop0 = InProp0;
}

ETbEnumEnum1 UTbEnumEnumInterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp1_Implementation(ETbEnumEnum1 InProp1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1_Implementation() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop1 == InProp1)
	{
		return;
	}	
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp1);	
	_SentData->Prop1 = InProp1;
}

ETbEnumEnum2 UTbEnumEnumInterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp2_Implementation(ETbEnumEnum2 InProp2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2_Implementation() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop2 == InProp2)
	{
		return;
	}	
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop2");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp2);	
	_SentData->Prop2 = InProp2;
}

ETbEnumEnum3 UTbEnumEnumInterfaceOLinkClient::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp3_Implementation(ETbEnumEnum3 InProp3)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp3_Implementation() == InProp3)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop3 == InProp3)
	{
		return;
	}	
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop3");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp3);	
	_SentData->Prop3 = InProp3;
}

ETbEnumEnum0 UTbEnumEnumInterfaceOLinkClient::Func0_Implementation(ETbEnumEnum0 Param0)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return ETbEnumEnum0::TEE_VALUE0;
	}
	TPromise<ETbEnumEnum0> Promise;
	Async(EAsyncExecution::Thread,
		[Param0, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<ETbEnumEnum0>());
				}
				else
				{
					UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Error, TEXT("Func0: OLink service returned empty value - should have returned type of ETbEnumEnum0"));
					Promise.SetValue(ETbEnumEnum0());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func0");
			m_sink->GetNode()->invokeRemote(memberId, {Param0}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum1 UTbEnumEnumInterfaceOLinkClient::Func1_Implementation(ETbEnumEnum1 Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return ETbEnumEnum1::TEE_VALUE1;
	}
	TPromise<ETbEnumEnum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<ETbEnumEnum1>());
				}
				else
				{
					UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Error, TEXT("Func1: OLink service returned empty value - should have returned type of ETbEnumEnum1"));
					Promise.SetValue(ETbEnumEnum1());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1");
			m_sink->GetNode()->invokeRemote(memberId, {Param1}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum2 UTbEnumEnumInterfaceOLinkClient::Func2_Implementation(ETbEnumEnum2 Param2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return ETbEnumEnum2::TEE_VALUE2;
	}
	TPromise<ETbEnumEnum2> Promise;
	Async(EAsyncExecution::Thread,
		[Param2, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<ETbEnumEnum2>());
				}
				else
				{
					UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Error, TEXT("Func2: OLink service returned empty value - should have returned type of ETbEnumEnum2"));
					Promise.SetValue(ETbEnumEnum2());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func2");
			m_sink->GetNode()->invokeRemote(memberId, {Param2}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum3 UTbEnumEnumInterfaceOLinkClient::Func3_Implementation(ETbEnumEnum3 Param3)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return ETbEnumEnum3::TEE_VALUE3;
	}
	TPromise<ETbEnumEnum3> Promise;
	Async(EAsyncExecution::Thread,
		[Param3, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<ETbEnumEnum3>());
				}
				else
				{
					UE_LOG(LogTbEnumEnumInterfaceOLinkClient, Error, TEXT("Func3: OLink service returned empty value - should have returned type of ETbEnumEnum3"));
					Promise.SetValue(ETbEnumEnum3());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func3");
			m_sink->GetNode()->invokeRemote(memberId, {Param3}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

bool UTbEnumEnumInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbEnumEnumInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bProp0Changed = fields.contains("prop0") && (Prop0 != fields["prop0"].get<ETbEnumEnum0>());
	if (bProp0Changed)
	{
		Prop0 = fields["prop0"].get<ETbEnumEnum0>();
		Execute__GetSignals(this)->OnProp0Changed.Broadcast(Prop0);
	}

	const bool bProp1Changed = fields.contains("prop1") && (Prop1 != fields["prop1"].get<ETbEnumEnum1>());
	if (bProp1Changed)
	{
		Prop1 = fields["prop1"].get<ETbEnumEnum1>();
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}

	const bool bProp2Changed = fields.contains("prop2") && (Prop2 != fields["prop2"].get<ETbEnumEnum2>());
	if (bProp2Changed)
	{
		Prop2 = fields["prop2"].get<ETbEnumEnum2>();
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}

	const bool bProp3Changed = fields.contains("prop3") && (Prop3 != fields["prop3"].get<ETbEnumEnum3>());
	if (bProp3Changed)
	{
		Prop3 = fields["prop3"].get<ETbEnumEnum3>();
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}
}

void UTbEnumEnumInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig0")
	{
		ETbEnumEnum0 Param0 = args[0].get<ETbEnumEnum0>();
		Execute__GetSignals(this)->OnSig0Signal.Broadcast(Param0);
		return;
	}

	if (signalName == "sig1")
	{
		ETbEnumEnum1 Param1 = args[0].get<ETbEnumEnum1>();
		Execute__GetSignals(this)->OnSig1Signal.Broadcast(Param1);
		return;
	}

	if (signalName == "sig2")
	{
		ETbEnumEnum2 Param2 = args[0].get<ETbEnumEnum2>();
		Execute__GetSignals(this)->OnSig2Signal.Broadcast(Param2);
		return;
	}

	if (signalName == "sig3")
	{
		ETbEnumEnum3 Param3 = args[0].get<ETbEnumEnum3>();
		Execute__GetSignals(this)->OnSig3Signal.Broadcast(Param3);
		return;
	}
}
