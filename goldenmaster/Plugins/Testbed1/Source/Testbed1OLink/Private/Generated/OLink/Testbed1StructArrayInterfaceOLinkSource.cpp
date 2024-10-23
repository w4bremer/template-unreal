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

#include "Testbed1StructArrayInterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Testbed1/Generated/api/Testbed1.json.adapter.h"
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
static const std::string Testbed1StructArrayInterfaceIdentifier{"testbed1.StructArrayInterface"};
}

DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceOLinkSource);
Testbed1StructArrayInterfaceOLinkSource::Testbed1StructArrayInterfaceOLinkSource()
	: Host(nullptr)
{
}

void Testbed1StructArrayInterfaceOLinkSource::setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkSource, Error, TEXT("Cannot set backend service to %s - interface Testbed1StructArrayInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	BackendService = InService;
}
void Testbed1StructArrayInterfaceOLinkSource::OnSigBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamBool};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnSigInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloat};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnSigString(const TArray<FTestbed1StructString>& ParamString)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamString};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropBool);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropString);
		}
	}
}

void Testbed1StructArrayInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string Testbed1StructArrayInterfaceOLinkSource::olinkObjectName()
{
	return Testbed1StructArrayInterfaceIdentifier;
}

nlohmann::json Testbed1StructArrayInterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed1StructArrayInterfaceOLinkAdapter which implements the Testbed1StructArrayInterface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "funcBool")
	{
		TArray<FTestbed1StructBool> ParamBool = args.at(0).get<TArray<FTestbed1StructBool>>();
		TArray<FTestbed1StructBool> result = BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
		return result;
	}
	if (path == "funcInt")
	{
		TArray<FTestbed1StructInt> ParamInt = args.at(0).get<TArray<FTestbed1StructInt>>();
		TArray<FTestbed1StructInt> result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
		return result;
	}
	if (path == "funcFloat")
	{
		TArray<FTestbed1StructFloat> ParamFloat = args.at(0).get<TArray<FTestbed1StructFloat>>();
		TArray<FTestbed1StructFloat> result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
		return result;
	}
	if (path == "funcString")
	{
		TArray<FTestbed1StructString> ParamString = args.at(0).get<TArray<FTestbed1StructString>>();
		TArray<FTestbed1StructString> result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
		return result;
	}
	return nlohmann::json();
}

void Testbed1StructArrayInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed1StructArrayInterfaceOLinkAdapter which implements the Testbed1StructArrayInterface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "propBool")
	{
		TArray<FTestbed1StructBool> PropBool = value.get<TArray<FTestbed1StructBool>>();
		BackendService->Execute_SetPropBool(BackendService.GetObject(), PropBool);
	}
	if (path == "propInt")
	{
		TArray<FTestbed1StructInt> PropInt = value.get<TArray<FTestbed1StructInt>>();
		BackendService->Execute_SetPropInt(BackendService.GetObject(), PropInt);
	}
	if (path == "propFloat")
	{
		TArray<FTestbed1StructFloat> PropFloat = value.get<TArray<FTestbed1StructFloat>>();
		BackendService->Execute_SetPropFloat(BackendService.GetObject(), PropFloat);
	}
	if (path == "propString")
	{
		TArray<FTestbed1StructString> PropString = value.get<TArray<FTestbed1StructString>>();
		BackendService->Execute_SetPropString(BackendService.GetObject(), PropString);
	}
}

nlohmann::json Testbed1StructArrayInterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter Testbed1StructArrayInterfaceOLinkAdapter which implements the Testbed1StructArrayInterface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"propBool", BackendService->Execute_GetPropBool(BackendService.GetObject())},
		{"propInt", BackendService->Execute_GetPropInt(BackendService.GetObject())},
		{"propFloat", BackendService->Execute_GetPropFloat(BackendService.GetObject())},
		{"propString", BackendService->Execute_GetPropString(BackendService.GetObject())}});
}