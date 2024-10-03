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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Testbed2NestedStruct1InterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Testbed2/Generated/api/Testbed2.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END

using namespace ApiGear::ObjectLink;

namespace
{
static const std::string Testbed2NestedStruct1InterfaceIdentifier{"testbed2.NestedStruct1Interface"};
}

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct1InterfaceOLinkSource);
Testbed2NestedStruct1InterfaceOLinkSource::Testbed2NestedStruct1InterfaceOLinkSource()
	: Host(nullptr)
{
}

void Testbed2NestedStruct1InterfaceOLinkSource::setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceOLinkSource, Error, TEXT("Cannot set backend service to %s - interface Testbed2NestedStruct1Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	BackendService = InService;
}
void Testbed2NestedStruct1InterfaceOLinkSource::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param1};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void Testbed2NestedStruct1InterfaceOLinkSource::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp1);
		}
	}
}

void Testbed2NestedStruct1InterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string Testbed2NestedStruct1InterfaceOLinkSource::olinkObjectName()
{
	return Testbed2NestedStruct1InterfaceIdentifier;
}

nlohmann::json Testbed2NestedStruct1InterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed2NestedStruct1InterfaceOLinkAdapter which implements the Testbed2NestedStruct1Interface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func1")
	{
		FTestbed2NestedStruct1 Param1 = args.at(0).get<FTestbed2NestedStruct1>();
		FTestbed2NestedStruct1 result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
		return result;
	}
	return nlohmann::json();
}

void Testbed2NestedStruct1InterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed2NestedStruct1InterfaceOLinkAdapter which implements the Testbed2NestedStruct1Interface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop1")
	{
		FTestbed2NestedStruct1 Prop1 = value.get<FTestbed2NestedStruct1>();
		BackendService->Execute_SetProp1(BackendService.GetObject(), Prop1);
	}
}

nlohmann::json Testbed2NestedStruct1InterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed2NestedStruct1InterfaceOLinkAdapter which implements the Testbed2NestedStruct1Interface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop1", BackendService->Execute_GetProp1(BackendService.GetObject())}});
}
