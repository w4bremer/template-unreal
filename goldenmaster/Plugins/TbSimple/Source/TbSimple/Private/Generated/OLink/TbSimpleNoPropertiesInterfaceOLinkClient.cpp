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

#include "Generated/olink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
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

UTbSimpleNoPropertiesInterfaceOLinkClient::UTbSimpleNoPropertiesInterfaceOLinkClient()
	: ITbSimpleNoPropertiesInterfaceInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.simple.NoPropertiesInterface");
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTbSimpleNoPropertiesInterfaceOLinkClient::Deinitialize()
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

void UTbSimpleNoPropertiesInterfaceOLinkClient::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

FTbSimpleNoPropertiesInterfaceSigVoidDelegate& UTbSimpleNoPropertiesInterfaceOLinkClient::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleNoPropertiesInterfaceSigBoolDelegate& UTbSimpleNoPropertiesInterfaceOLinkClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::FuncVoid_Implementation()
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetNoPropertiesInterfaceStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcVoid"), {}, GetNoPropertiesInterfaceStateFunc);
}

bool UTbSimpleNoPropertiesInterfaceOLinkClient::FuncBool_Implementation(bool bParamBool)
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
			ApiGear::ObjectLink::InvokeReplyFunc GetNoPropertiesInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<bool>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool"), {bParamBool}, GetNoPropertiesInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::emitSignal(const std::string& signalId, const nlohmann::json& args)
{
	std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (MemberName == "sigVoid")
	{
		Execute_BroadcastSigVoid(this);
		return;
	}
	if (MemberName == "sigBool")
	{
		Execute_BroadcastSigBool(this, args[0].get<bool>());
		return;
	}
}