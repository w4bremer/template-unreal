
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sMSGBUS_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMsgBusAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$Iface}}Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "{{$Iface}}MsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct F{{$Iface}}DiscoveryMessage;
struct F{{$DisplayName}}ServiceAnnouncementReplyMessage;
struct F{{$Iface}}PingMessage;
struct F{{$Iface}}ClientDisconnectMessage;
{{- range $i, $e := .Interface.Signals }}
struct F{{$Iface}}{{Camel .Name}}SignalMessage;
{{- end }}
{{- range $i, $e := .Interface.Properties }}
struct F{{$Iface}}Set{{Camel .Name}}RequestMessage;
struct F{{$Iface}}{{Camel .Name}}ChangedMessage;
{{- end }}
{{- range $i, $e := .Interface.Operations }}
struct F{{$DisplayName}}{{Camel .Name}}RequestMessage;
{{- end }}

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}ClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}ClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}ClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}ClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}MsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type I{{Camel .Module.Name}}{{Camel .Interface.Name}}
/// and holds the corresponding {{$Iface}}OLinkSource OLink source object
UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "New client connected")
	F{{$Iface}}ClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Client disconnected")
	F{{$Iface}}ClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Client timed out")
	F{{$Iface}}ClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Clients connected count changed")
	F{{$Iface}}ClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void _setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> {{Camel .Module.Name}}{{Camel .Interface.Name}}MsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const F{{$Iface}}DiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const F{{$Iface}}ServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const F{{$Iface}}PingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const F{{$Iface}}ClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- range $i, $e := .Interface.Operations }}
	void On{{Camel .Name}}Request(const F{{$Iface}}{{Camel .Name}}RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- range $i, $e := .Interface.Properties }}
{{- if not .IsReadOnly }}
	void OnSet{{Camel .Name}}Request(const F{{$Iface}}Set{{Camel .Name}}RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- end }}

	// signals
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}Changed({{ueParam "" .}});
{{- end }}

	// delegate handles
{{- range .Interface.Properties }}
	FDelegateHandle On{{Camel .Name}}ChangedHandle;
{{- end }}
{{- range .Interface.Signals }}
	FDelegateHandle On{{Camel .Name}}SignalHandle;
{{- end }}

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}> BackendService;

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
