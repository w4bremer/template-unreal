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

#include "TbEnumEnumInterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbEnum.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTbEnumEnumInterfaceOLinkClient::UTbEnumEnumInterfaceOLinkClient()
	: ITbEnumEnumInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
{
}

void UTbEnumEnumInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTbEnumEnumInterfaceOLinkClient::Deinitialize()
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

void UTbEnumEnumInterfaceOLinkClient::BroadcastSig0_Implementation(const ETbEnumEnum0& Param0)
{
	Sig0Signal.Broadcast(Param0);
}

FTbEnumEnumInterfaceSig0Delegate& UTbEnumEnumInterfaceOLinkClient::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastSig1_Implementation(const ETbEnumEnum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbEnumEnumInterfaceSig1Delegate& UTbEnumEnumInterfaceOLinkClient::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastSig2_Implementation(const ETbEnumEnum2& Param2)
{
	Sig2Signal.Broadcast(Param2);
}

FTbEnumEnumInterfaceSig2Delegate& UTbEnumEnumInterfaceOLinkClient::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastSig3_Implementation(const ETbEnumEnum3& Param3)
{
	Sig3Signal.Broadcast(Param3);
}

FTbEnumEnumInterfaceSig3Delegate& UTbEnumEnumInterfaceOLinkClient::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastProp0Changed_Implementation(const ETbEnumEnum0& InProp0)
{
	Prop0 = InProp0;
	Prop0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceOLinkClient::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop0", InProp0);
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterfaceOLinkClient::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastProp1Changed_Implementation(const ETbEnumEnum1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop1", InProp1);
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterfaceOLinkClient::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastProp2Changed_Implementation(const ETbEnumEnum2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop2", InProp2);
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterfaceOLinkClient::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbEnumEnumInterfaceOLinkClient::BroadcastProp3Changed_Implementation(const ETbEnumEnum3& InProp3)
{
	Prop3 = InProp3;
	Prop3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceOLinkClient::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceOLinkClient::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop3", InProp3);
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterfaceOLinkClient::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

ETbEnumEnum0 UTbEnumEnumInterfaceOLinkClient::Func0_Implementation(const ETbEnumEnum0& Param0)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum0::VALUE0;
	}
	TPromise<ETbEnumEnum0> Promise;
	Async(EAsyncExecution::Thread,
		[Param0, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum0>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func0", {Param0}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum1 UTbEnumEnumInterfaceOLinkClient::Func1_Implementation(const ETbEnumEnum1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum1::VALUE1;
	}
	TPromise<ETbEnumEnum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum1>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func1", {Param1}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum2 UTbEnumEnumInterfaceOLinkClient::Func2_Implementation(const ETbEnumEnum2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum2::VALUE2;
	}
	TPromise<ETbEnumEnum2> Promise;
	Async(EAsyncExecution::Thread,
		[Param2, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum2>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func2", {Param2}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum3 UTbEnumEnumInterfaceOLinkClient::Func3_Implementation(const ETbEnumEnum3& Param3)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum3::VALUE3;
	}
	TPromise<ETbEnumEnum3> Promise;
	Async(EAsyncExecution::Thread,
		[Param3, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum3>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func3", {Param3}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbEnumEnumInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop0"))
	{
		if (Prop0 != fields["prop0"].get<ETbEnumEnum0>())
		{
			Prop0 = fields["prop0"].get<ETbEnumEnum0>();
			Execute_BroadcastProp0Changed(this, Prop0);
		}
	}
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<ETbEnumEnum1>())
		{
			Prop1 = fields["prop1"].get<ETbEnumEnum1>();
			Execute_BroadcastProp1Changed(this, Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<ETbEnumEnum2>())
		{
			Prop2 = fields["prop2"].get<ETbEnumEnum2>();
			Execute_BroadcastProp2Changed(this, Prop2);
		}
	}
	if (fields.contains("prop3"))
	{
		if (Prop3 != fields["prop3"].get<ETbEnumEnum3>())
		{
			Prop3 = fields["prop3"].get<ETbEnumEnum3>();
			Execute_BroadcastProp3Changed(this, Prop3);
		}
	}
}

std::string UTbEnumEnumInterfaceOLinkClient::olinkObjectName()
{
	return "tb.enum.EnumInterface";
}

void UTbEnumEnumInterfaceOLinkClient::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig0")
	{
		Execute_BroadcastSig0(this, args[0].get<ETbEnumEnum0>());
		return;
	}
	if (path == "sig1")
	{
		Execute_BroadcastSig1(this, args[0].get<ETbEnumEnum1>());
		return;
	}
	if (path == "sig2")
	{
		Execute_BroadcastSig2(this, args[0].get<ETbEnumEnum2>());
		return;
	}
	if (path == "sig3")
	{
		Execute_BroadcastSig3(this, args[0].get<ETbEnumEnum3>());
		return;
	}
}

void UTbEnumEnumInterfaceOLinkClient::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTbEnumEnumInterfaceOLinkClient::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTbEnumEnumInterfaceOLinkClient::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
