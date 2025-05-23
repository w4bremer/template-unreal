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

#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "Testbed2ManyParamInterfaceOLinkClient.generated.h"

struct Testbed2ManyParamInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2OLINK_API UTestbed2ManyParamInterfaceOLinkClient : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed2ManyParamInterfacePropertiesData>
	UTestbed2ManyParamInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed2ManyParamInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	int32 GetProp1() const override;
	void SetProp1(int32 Prop1) override;

	int32 GetProp2() const override;
	void SetProp2(int32 Prop2) override;

	int32 GetProp3() const override;
	void SetProp3(int32 Prop3) override;

	int32 GetProp4() const override;
	void SetProp4(int32 Prop4) override;

	// operations
	int32 Func1(int32 Param1) override;

	int32 Func2(int32 Param1, int32 Param2) override;

	int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<Testbed2ManyParamInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
