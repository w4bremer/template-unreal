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

#include "TbSame1SameEnum2InterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSame1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END

using namespace ApiGear::ObjectLink;

namespace
{
static const std::string TbSame1SameEnum2InterfaceIdentifier{"tb.same1.SameEnum2Interface"};
}

DEFINE_LOG_CATEGORY(LogTbSame1SameEnum2InterfaceOLinkSource);
TbSame1SameEnum2InterfaceOLinkSource::TbSame1SameEnum2InterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSame1SameEnum2InterfaceOLinkSource::setBackendService(TScriptInterface<ITbSame1SameEnum2InterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceOLinkSource, Error, TEXT("Cannot set backend service to %s - interface TbSame1SameEnum2Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	BackendService = InService;
}
void TbSame1SameEnum2InterfaceOLinkSource::OnSig1(ETbSame1Enum1 Param1)
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

void TbSame1SameEnum2InterfaceOLinkSource::OnSig2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param1, Param2};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSame1SameEnum2InterfaceOLinkSource::OnProp1Changed(ETbSame1Enum1 InProp1)
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

void TbSame1SameEnum2InterfaceOLinkSource::OnProp2Changed(ETbSame1Enum2 InProp2)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp2);
		}
	}
}

void TbSame1SameEnum2InterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSame1SameEnum2InterfaceOLinkSource::olinkObjectName()
{
	return TbSame1SameEnum2InterfaceIdentifier;
}

nlohmann::json TbSame1SameEnum2InterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameEnum2InterfaceOLinkAdapter which implements the TbSame1SameEnum2Interface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func1")
	{
		ETbSame1Enum1 Param1 = args.at(0);
		ETbSame1Enum1 result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
		return result;
	}
	if (path == "func2")
	{
		ETbSame1Enum1 Param1 = args.at(0);
		ETbSame1Enum2 Param2 = args.at(1);
		ETbSame1Enum1 result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
		return result;
	}
	return nlohmann::json();
}

void TbSame1SameEnum2InterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameEnum2InterfaceOLinkAdapter which implements the TbSame1SameEnum2Interface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop1")
	{
		ETbSame1Enum1 Prop1 = value.get<ETbSame1Enum1>();
		BackendService->Execute_SetProp1(BackendService.GetObject(), Prop1);
	}
	if (path == "prop2")
	{
		ETbSame1Enum2 Prop2 = value.get<ETbSame1Enum2>();
		BackendService->Execute_SetProp2(BackendService.GetObject(), Prop2);
	}
}

nlohmann::json TbSame1SameEnum2InterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameEnum2InterfaceOLinkAdapter which implements the TbSame1SameEnum2Interface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop1", BackendService->Execute_GetProp1(BackendService.GetObject())},
		{"prop2", BackendService->Execute_GetProp2(BackendService.GetObject())}});
}
