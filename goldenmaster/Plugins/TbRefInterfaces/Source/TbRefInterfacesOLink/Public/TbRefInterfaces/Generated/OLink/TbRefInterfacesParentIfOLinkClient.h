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
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "TbRefInterfacesParentIfOLinkClient.generated.h"

struct TbRefInterfacesParentIfPropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesParentIfOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESOLINK_API UTbRefInterfacesParentIfOLinkClient : public UAbstractTbRefInterfacesParentIf
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesParentIfOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbRefInterfacesParentIfPropertiesData>
	UTbRefInterfacesParentIfOLinkClient(FVTableHelper& Helper);
	virtual ~UTbRefInterfacesParentIfOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf) override;

	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf) override;

	// operations
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override;

	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbRefInterfacesParentIfPropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
