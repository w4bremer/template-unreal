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

#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImportCounterInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbRefInterfacesImportCounterMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesImportCounterDiscoveryMessage;
struct FTbRefInterfacesImportCounterServiceAnnouncementReplyMessage;
struct FTbRefInterfacesImportCounterPingMessage;
struct FTbRefInterfacesImportCounterClientDisconnectMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesImportCounterMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbRefInterfacesImportCounter
/// and holds the corresponding TbRefInterfacesImportCounterOLinkSource OLink source object
UCLASS(BlueprintType)
class TBREFINTERFACESIMPORTMSGBUS_API UTbRefInterfacesImportCounterMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesImportCounterMsgBusAdapter();
	virtual ~UTbRefInterfacesImportCounterMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "New client connected")
	FTbRefInterfacesImportCounterClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Client disconnected")
	FTbRefInterfacesImportCounterClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Client timed out")
	FTbRefInterfacesImportCounterClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Clients connected count changed")
	FTbRefInterfacesImportCounterClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter")
	void _setBackendService(TScriptInterface<ITbRefInterfacesImportCounter> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesImportCounterMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbRefInterfacesImportCounterDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbRefInterfacesImportCounterServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbRefInterfacesImportCounterPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbRefInterfacesImportCounterClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals

	// delegate handles

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfacesImport|Counter")
	TScriptInterface<ITbRefInterfacesImportCounter> BackendService;

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
