#include "AbstractApiGearConnection.h"

DEFINE_LOG_CATEGORY(LogApiGearConnection);

#if (ENGINE_MAJOR_VERSION >= 5)
FTSTicker& GetCoreTicker()
{
	return FTSTicker::GetCoreTicker();
}
#else
FTicker& GetCoreTicker()
{
	return FTicker::GetCoreTicker();
}
#endif

UAbstractApiGearConnection::UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bIsAutoReconnectEnabled(true)
	, bStopReconnectingRequested(false)
{
	RetryTickerDelegate.BindUFunction(this, "Connect");
}

FApiGearConnectionIsConnectedDelegate& UAbstractApiGearConnection::GetIsConnectedChangedDelegate()
{
	return IsConnectedChanged;
}

FApiGearConnectionStateChangedDelegate& UAbstractApiGearConnection::GetConnectionStateChangedDelegate()
{
	return ConnectionStateChanged;
}

void UAbstractApiGearConnection::OnConnected()
{
	SetConnectionState(EApiGearConnectionState::Connected);

	// disable reconnect ticker
	GetCoreTicker().RemoveTicker(RetryTickerHandle);

	OnConnected_Implementation();
}

void UAbstractApiGearConnection::OnDisconnected(bool bReconnect)
{
	OnDisconnected_Implementation(bReconnect);

	SetConnectionState(EApiGearConnectionState::Disconnected);

	if (bIsAutoReconnectEnabled && bReconnect && !bStopReconnectingRequested)
	{
		RetryTickerHandle = GetCoreTicker().AddTicker(RetryTickerDelegate, 1.0f);
	}

	if (bStopReconnectingRequested)
	{
		bStopReconnectingRequested = false;
	}
}

void UAbstractApiGearConnection::Connect()
{
	if (IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		return;
	}
	SetConnectionState(EApiGearConnectionState::Connecting);

	Connect_Implementation();
}

void UAbstractApiGearConnection::Disconnect()
{
	if (!IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		UAbstractApiGearConnection::StopReconnecting();
		return;
	}

	Disconnect_Implementation();
}

void UAbstractApiGearConnection::StopReconnecting()
{
	bStopReconnectingRequested = true;
	// disable reconnect ticker
	GetCoreTicker().RemoveTicker(RetryTickerHandle);
}

void UAbstractApiGearConnection::SetAutoReconnectEnabled(bool enabled)
{
	if (bIsAutoReconnectEnabled == true && enabled == false)
	{
		// disable reconnect ticker
		GetCoreTicker().RemoveTicker(RetryTickerHandle);
	}
	bIsAutoReconnectEnabled = enabled;
}

bool UAbstractApiGearConnection::IsAutoReconnectEnabled() const
{
	return bIsAutoReconnectEnabled;
}

EApiGearConnectionState UAbstractApiGearConnection::GetConnectionState()
{
	return ConnectionState;
}

void UAbstractApiGearConnection::SetConnectionState(EApiGearConnectionState State)
{
	ConnectionState = State;
	ConnectionStateChanged.Broadcast(ConnectionState);
	IsConnectedChanged.Broadcast(ConnectionState == EApiGearConnectionState::Connected);
}
