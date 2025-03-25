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

#include "TbRefInterfaces/Generated/api/TbRefInterfacesParentIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbRefInterfacesParentIfMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesParentIfDiscoveryMessage;
struct FTbRefInterfacesParentIfServiceAnnouncementReplyMessage;
struct FTbRefInterfacesParentIfPingMessage;
struct FTbRefInterfacesParentIfClientDisconnectMessage;
struct FTbRefInterfacesParentIfLocalIfSignalSignalMessage;
struct FTbRefInterfacesParentIfImportedIfSignalSignalMessage;
struct FTbRefInterfacesParentIfSetLocalIfRequestMessage;
struct FTbRefInterfacesParentIfLocalIfChangedMessage;
struct FTbRefInterfacesParentIfSetImportedIfRequestMessage;
struct FTbRefInterfacesParentIfImportedIfChangedMessage;
struct FTbRefInterfacesParentIfLocalIfMethodRequestMessage;
struct FTbRefInterfacesParentIfImportedIfMethodRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesParentIfMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbRefInterfacesParentIf
/// and holds the corresponding TbRefInterfacesParentIfOLinkSource OLink source object
UCLASS(BlueprintType)
class TBREFINTERFACESMSGBUS_API UTbRefInterfacesParentIfMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesParentIfMsgBusAdapter();
	virtual ~UTbRefInterfacesParentIfMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "New client connected")
	FTbRefInterfacesParentIfClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Client disconnected")
	FTbRefInterfacesParentIfClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Client timed out")
	FTbRefInterfacesParentIfClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Clients connected count changed")
	FTbRefInterfacesParentIfClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	void _setBackendService(TScriptInterface<ITbRefInterfacesParentIf> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesParentIfMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbRefInterfacesParentIfDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbRefInterfacesParentIfServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbRefInterfacesParentIfPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbRefInterfacesParentIfClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodRequest(const FTbRefInterfacesParentIfLocalIfMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodRequest(const FTbRefInterfacesParentIfImportedIfMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetLocalIfRequest(const FTbRefInterfacesParentIfSetLocalIfRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetImportedIfRequest(const FTbRefInterfacesParentIfSetImportedIfRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfChanged(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfChanged(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf);

	// delegate handles
	FDelegateHandle OnLocalIfChangedHandle;
	FDelegateHandle OnImportedIfChangedHandle;
	FDelegateHandle OnLocalIfSignalSignalHandle;
	FDelegateHandle OnImportedIfSignalSignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|ParentIf")
	TScriptInterface<ITbRefInterfacesParentIf> BackendService;

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
