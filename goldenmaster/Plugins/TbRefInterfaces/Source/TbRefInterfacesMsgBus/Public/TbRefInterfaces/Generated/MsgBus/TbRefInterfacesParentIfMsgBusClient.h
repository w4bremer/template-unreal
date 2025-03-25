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

#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesParentIf.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbRefInterfacesParentIfMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesParentIfInitMessage;
struct FTbRefInterfacesParentIfPongMessage;
struct FTbRefInterfacesParentIfServiceDisconnectMessage;
struct FTbRefInterfacesParentIfLocalIfSignalSignalMessage;
struct FTbRefInterfacesParentIfImportedIfSignalSignalMessage;
struct FTbRefInterfacesParentIfLocalIfChangedMessage;
struct FTbRefInterfacesParentIfImportedIfChangedMessage;
struct FTbRefInterfacesParentIfLocalIfMethodReplyMessage;
struct FTbRefInterfacesParentIfImportedIfMethodReplyMessage;

USTRUCT(BlueprintType)
struct FTbRefInterfacesParentIfStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfStatsUpdatedDelegate, FTbRefInterfacesParentIfStats, Stats);

struct TbRefInterfacesParentIfPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesParentIfMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesParentIfConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESMSGBUS_API UTbRefInterfacesParentIfMsgBusClient : public UAbstractTbRefInterfacesParentIf
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesParentIfMsgBusClient();
	virtual ~UTbRefInterfacesParentIfMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	const FTbRefInterfacesParentIfStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Statistics Updated")
	FTbRefInterfacesParentIfStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Connection Status Changed")
	FTbRefInterfacesParentIfConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefInterfacesParentIfConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf) override;

	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf) override;

	// operations
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override;

	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesParentIfMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbRefInterfacesParentIfStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbRefInterfacesParentIfInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbRefInterfacesParentIfPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbRefInterfacesParentIfServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfSignal(const FTbRefInterfacesParentIfLocalIfSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfSignal(const FTbRefInterfacesParentIfImportedIfSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfChanged(const FTbRefInterfacesParentIfLocalIfChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfChanged(const FTbRefInterfacesParentIfImportedIfChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodReply(const FTbRefInterfacesParentIfLocalIfMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodReply(const FTbRefInterfacesParentIfImportedIfMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbRefInterfacesParentIfPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
