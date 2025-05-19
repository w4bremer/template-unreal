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

#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2InterfaceOLinkSource, Log, All);
/** @brief handles OLink network interactions specific to ITbSame2SameEnum2Interface */
class TbSame2SameEnum2InterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit TbSame2SameEnum2InterfaceOLinkSource();
	virtual ~TbSame2SameEnum2InterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITbSame2SameEnum2Interface> InService);

	/** set the OLink host to be used */
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

	//
	// IObjectSource interface
	//

	// unique identifier of this module->interface
	std::string olinkObjectName() override;

	nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;
	void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
	void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* node) override{};
	void olinkUnlinked(const std::string& objectId) override{};
	nlohmann::json olinkCollectProperties() override;

	// signals
	void OnSig1(ETbSame2Enum1 Param1);
	void OnSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	void OnProp1Changed(ETbSame2Enum1 Prop1);
	void OnProp2Changed(ETbSame2Enum2 Prop2);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITbSame2SameEnum2Interface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UOLinkHost> Host;
};
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
class TbSame2SameEnum2InterfaceOLinkSource
{
};
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
