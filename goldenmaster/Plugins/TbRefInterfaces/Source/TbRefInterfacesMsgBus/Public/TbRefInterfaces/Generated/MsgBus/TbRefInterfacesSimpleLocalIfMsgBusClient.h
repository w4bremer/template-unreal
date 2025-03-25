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

#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesSimpleLocalIf.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbRefInterfacesSimpleLocalIfMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesSimpleLocalIfInitMessage;
struct FTbRefInterfacesSimpleLocalIfPongMessage;
struct FTbRefInterfacesSimpleLocalIfServiceDisconnectMessage;
struct FTbRefInterfacesSimpleLocalIfIntSignalSignalMessage;
struct FTbRefInterfacesSimpleLocalIfIntPropertyChangedMessage;
struct FTbRefInterfacesSimpleLocalIfIntMethodReplyMessage;

USTRUCT(BlueprintType)
struct FTbRefInterfacesSimpleLocalIfStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfStatsUpdatedDelegate, FTbRefInterfacesSimpleLocalIfStats, Stats);

struct TbRefInterfacesSimpleLocalIfPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesSimpleLocalIfMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesSimpleLocalIfConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESMSGBUS_API UTbRefInterfacesSimpleLocalIfMsgBusClient : public UAbstractTbRefInterfacesSimpleLocalIf
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesSimpleLocalIfMsgBusClient();
	virtual ~UTbRefInterfacesSimpleLocalIfMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote")
	const FTbRefInterfacesSimpleLocalIfStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Statistics Updated")
	FTbRefInterfacesSimpleLocalIfStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf|Remote", DisplayName = "Connection Status Changed")
	FTbRefInterfacesSimpleLocalIfConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefInterfacesSimpleLocalIfConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 IntProperty) override;

	// operations
	int32 IntMethod(int32 Param) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesSimpleLocalIfMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbRefInterfacesSimpleLocalIfStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbRefInterfacesSimpleLocalIfInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbRefInterfacesSimpleLocalIfPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbRefInterfacesSimpleLocalIfServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntSignal(const FTbRefInterfacesSimpleLocalIfIntSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntPropertyChanged(const FTbRefInterfacesSimpleLocalIfIntPropertyChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntMethodReply(const FTbRefInterfacesSimpleLocalIfIntMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbRefInterfacesSimpleLocalIfPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
