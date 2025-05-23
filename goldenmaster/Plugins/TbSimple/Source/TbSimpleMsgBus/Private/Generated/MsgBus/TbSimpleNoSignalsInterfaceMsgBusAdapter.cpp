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

#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusAdapter.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSimpleNoSignalsInterfaceMsgBusAdapter::UTbSimpleNoSignalsInterfaceMsgBusAdapter()
{
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSimpleNoSignalsInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/NoSignalsInterface/Service")
		.Handling<FTbSimpleNoSignalsInterfaceDiscoveryMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSimpleNoSignalsInterfacePingMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSimpleNoSignalsInterfaceClientDisconnectMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncVoidRequest)
		.Handling<FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Build();
	// clang-format on

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Subscribe<FTbSimpleNoSignalsInterfaceDiscoveryMessage>();
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTbSimpleNoSignalsInterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSimpleNoSignalsInterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTbSimpleNoSignalsInterfaceMsgBusAdapter::_IsListening() const
{
	return TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoSignalsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoSignalsInterface"));
		if (OnPropBoolChangedHandle.IsValid())
		{
			BackendSignals->OnPropBoolChanged.Remove(OnPropBoolChangedHandle);
			OnPropBoolChangedHandle.Reset();
		}
		if (OnPropIntChangedHandle.IsValid())
		{
			BackendSignals->OnPropIntChanged.Remove(OnPropIntChangedHandle);
			OnPropIntChangedHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoSignalsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoSignalsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleNoSignalsInterface"));
	// connect property changed signals or simple events
	OnPropBoolChangedHandle = BackendSignals->OnPropBoolChanged.AddUObject(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropBoolChanged);
	OnPropIntChangedHandle = BackendSignals->OnPropIntChanged.AddUObject(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropIntChanged);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSimpleNoSignalsInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTbSimpleNoSignalsInterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->bPropBool = BackendService->GetPropBool();
	msg->PropInt = BackendService->GetPropInt();

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPing(const FTbSimpleNoSignalsInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoSignalsInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnClientDisconnected(const FTbSimpleNoSignalsInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_CheckClientTimeouts()
{
	float CurrentTime = FPlatformTime::Seconds();
	TArray<FMessageAddress> TimedOutClients;

	for (const auto& ClientPair : ConnectedClientsTimestamps)
	{
		const double Delta = (CurrentTime - ClientPair.Value) * 1000;

		if (Delta > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			TimedOutClients.Add(ClientPair.Key);
		}
	}

	for (const auto& ClientAddress : TimedOutClients)
	{
		_OnClientTimeout.Broadcast(ClientAddress.ToString());
		ConnectedClientsTimestamps.Remove(ClientAddress);
	}
	_UpdateClientsConnected();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncVoidRequest(const FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	BackendService->FuncVoid();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->FuncBool(InMessage.bParamBool);

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetPropBool(InMessage.bPropBool);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropBoolChanged(bool bInPropBool)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSimpleNoSignalsInterfacePropBoolChangedMessage();
	msg->bPropBool = bInPropBool;

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePropBoolChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropIntRequest(const FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetPropInt(InMessage.PropInt);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropIntChanged(int32 InPropInt)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSimpleNoSignalsInterfacePropIntChangedMessage();
	msg->PropInt = InPropInt;

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePropIntChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
