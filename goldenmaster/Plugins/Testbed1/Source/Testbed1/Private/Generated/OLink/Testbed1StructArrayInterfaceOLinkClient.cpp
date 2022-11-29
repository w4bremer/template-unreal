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

#include "Testbed1StructArrayInterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTestbed1StructArrayInterfaceOLinkClient::UTestbed1StructArrayInterfaceOLinkClient()
	: ITestbed1StructArrayInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
{
}

void UTestbed1StructArrayInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

void UTestbed1StructArrayInterfaceOLinkClient::Deinitialize()
{
	Super::Deinitialize();
	ClientRegistry::get().removeObjectSink(this);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(olinkObjectName());
	}
	m_isReady = false;
	m_node = nullptr;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructArrayInterface/propBool", InPropBool);
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructArrayInterface/propInt", InPropInt);
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructArrayInterface/propFloat", InPropFloat);
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructArrayInterfaceOLinkClient::BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructArrayInterface/propString", InPropString);
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& UTestbed1StructArrayInterfaceOLinkClient::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructArrayInterface/funcBool", {ParamBool}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructArrayInterface/funcInt", {ParamInt}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructArrayInterface/funcFloat", {ParamFloat}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceOLinkClient::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructArrayInterface/funcString", {ParamString}, GetStructArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (PropBool != fields["propBool"].get<TArray<FTestbed1StructBool>>())
		{
			PropBool = fields["propBool"].get<TArray<FTestbed1StructBool>>();
			Execute_BroadcastPropBoolChanged(this, PropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>())
		{
			PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
			Execute_BroadcastPropIntChanged(this, PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>())
		{
			PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
			Execute_BroadcastPropFloatChanged(this, PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<TArray<FTestbed1StructString>>())
		{
			PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
			Execute_BroadcastPropStringChanged(this, PropString);
		}
	}
}

std::string UTestbed1StructArrayInterfaceOLinkClient::olinkObjectName()
{
	return "testbed1.StructArrayInterface";
}

void UTestbed1StructArrayInterfaceOLinkClient::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sigBool")
	{
		Execute_BroadcastSigBool(this, args[0].get<TArray<FTestbed1StructBool>>());
		return;
	}
	if (path == "sigInt")
	{
		Execute_BroadcastSigInt(this, args[0].get<TArray<FTestbed1StructInt>>());
		return;
	}
	if (path == "sigFloat")
	{
		Execute_BroadcastSigFloat(this, args[0].get<TArray<FTestbed1StructFloat>>());
		return;
	}
	if (path == "sigString")
	{
		Execute_BroadcastSigString(this, args[0].get<TArray<FTestbed1StructString>>());
		return;
	}
}

void UTestbed1StructArrayInterfaceOLinkClient::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTestbed1StructArrayInterfaceOLinkClient::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTestbed1StructArrayInterfaceOLinkClient::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
