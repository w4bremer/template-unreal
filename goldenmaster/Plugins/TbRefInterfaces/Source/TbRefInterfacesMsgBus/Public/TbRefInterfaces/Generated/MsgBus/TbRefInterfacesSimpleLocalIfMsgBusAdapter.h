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
#pragma once

#include "TbRefInterfaces/Generated/api/TbRefInterfacesSimpleLocalIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbRefInterfacesSimpleLocalIfMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesSimpleLocalIfDiscoveryMessage;
struct FTbRefInterfacesSimpleLocalIfServiceAnnouncementReplyMessage;
struct FTbRefInterfacesSimpleLocalIfPingMessage;
struct FTbRefInterfacesSimpleLocalIfClientDisconnectMessage;
struct FTbRefInterfacesSimpleLocalIfIntSignalSignalMessage;
struct FTbRefInterfacesSimpleLocalIfSetIntPropertyRequestMessage;
struct FTbRefInterfacesSimpleLocalIfIntPropertyChangedMessage;
struct FTbRefInterfacesSimpleLocalIfIntMethodRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesSimpleLocalIfMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbRefInterfacesSimpleLocalIf
/// and holds the corresponding TbRefInterfacesSimpleLocalIfOLinkSource OLink source object
UCLASS(BlueprintType)
class TBREFINTERFACESMSGBUS_API UTbRefInterfacesSimpleLocalIfMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesSimpleLocalIfMsgBusAdapter();
	virtual ~UTbRefInterfacesSimpleLocalIfMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "New client connected")
	FTbRefInterfacesSimpleLocalIfClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Client disconnected")
	FTbRefInterfacesSimpleLocalIfClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Client timed out")
	FTbRefInterfacesSimpleLocalIfClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Clients connected count changed")
	FTbRefInterfacesSimpleLocalIfClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	void _setBackendService(TScriptInterface<ITbRefInterfacesSimpleLocalIf> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesSimpleLocalIfMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbRefInterfacesSimpleLocalIfDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbRefInterfacesSimpleLocalIfServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbRefInterfacesSimpleLocalIfPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbRefInterfacesSimpleLocalIfClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntMethodRequest(const FTbRefInterfacesSimpleLocalIfIntMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetIntPropertyRequest(const FTbRefInterfacesSimpleLocalIfSetIntPropertyRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntSignal(int32 Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntPropertyChanged(int32 IntProperty);

	// delegate handles
	FDelegateHandle OnIntPropertyChangedHandle;
	FDelegateHandle OnIntSignalSignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	bool _CheckClientTimeoutsTick(float DeltaTime);
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
