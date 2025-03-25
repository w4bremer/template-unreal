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

#include "TbRefInterfacesImport/Generated/api/AbstractTbRefInterfacesImportCounter.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbRefInterfacesImportCounterMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefInterfacesImportCounterInitMessage;
struct FTbRefInterfacesImportCounterPongMessage;
struct FTbRefInterfacesImportCounterServiceDisconnectMessage;

USTRUCT(BlueprintType)
struct FTbRefInterfacesImportCounterStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterStatsUpdatedDelegate, FTbRefInterfacesImportCounterStats, Stats);
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesImportCounterMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefInterfacesImportCounterConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESIMPORTMSGBUS_API UTbRefInterfacesImportCounterMsgBusClient : public UAbstractTbRefInterfacesImportCounter
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesImportCounterMsgBusClient();
	virtual ~UTbRefInterfacesImportCounterMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote")
	const FTbRefInterfacesImportCounterStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Statistics Updated")
	FTbRefInterfacesImportCounterStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfacesImport|Counter|Remote", DisplayName = "Connection Status Changed")
	FTbRefInterfacesImportCounterConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefInterfacesImportCounterConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	// operations

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefInterfacesImportCounterMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbRefInterfacesImportCounterStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbRefInterfacesImportCounterInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbRefInterfacesImportCounterPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbRefInterfacesImportCounterServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
};
