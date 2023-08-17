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

#include "TbSimpleSimpleArrayInterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
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
static const std::string TbSimpleSimpleArrayInterfaceIdentifier{"tb.simple.SimpleArrayInterface"};
}
TbSimpleSimpleArrayInterfaceOLinkSource::TbSimpleSimpleArrayInterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSimpleSimpleArrayInterfaceOLinkSource::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot set backend service to %s - interface TbSimpleSimpleArrayInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// set to new backend
	BackendService = InService;
}
void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigBool(const TArray<bool>& ParamBool)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigInt(const TArray<int32>& ParamInt)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigInt32(const TArray<int32>& ParamInt32)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt32};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigInt64(const TArray<int64>& ParamInt64)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt64};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigFloat(const TArray<float>& ParamFloat)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigFloat32(const TArray<float>& ParamFloa32)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloa32};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigFloat64(const TArray<double>& ParamFloat64)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloat64};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnSigString(const TArray<FString>& ParamString)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropBoolChanged(const TArray<bool>& InPropBool)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropIntChanged(const TArray<int32>& InPropInt)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt32);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt64);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropFloatChanged(const TArray<float>& InPropFloat)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat32);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat64);
		}
	}
}

void TbSimpleSimpleArrayInterfaceOLinkSource::OnPropStringChanged(const TArray<FString>& InPropString)
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

void TbSimpleSimpleArrayInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSimpleSimpleArrayInterfaceOLinkSource::olinkObjectName()
{
	return TbSimpleSimpleArrayInterfaceIdentifier;
}

nlohmann::json TbSimpleSimpleArrayInterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	const std::string path = Name::getMemberName(methodId);
	if (path == "funcBool")
	{
		TArray<bool> ParamBool = args.at(0);
		TArray<bool> result = BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
		return result;
	}
	if (path == "funcInt")
	{
		TArray<int32> ParamInt = args.at(0);
		TArray<int32> result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
		return result;
	}
	if (path == "funcInt32")
	{
		TArray<int32> ParamInt32 = args.at(0);
		TArray<int32> result = BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
		return result;
	}
	if (path == "funcInt64")
	{
		TArray<int64> ParamInt64 = args.at(0);
		TArray<int64> result = BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
		return result;
	}
	if (path == "funcFloat")
	{
		TArray<float> ParamFloat = args.at(0);
		TArray<float> result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
		return result;
	}
	if (path == "funcFloat32")
	{
		TArray<float> ParamFloat32 = args.at(0);
		TArray<float> result = BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
		return result;
	}
	if (path == "funcFloat64")
	{
		TArray<double> ParamFloat = args.at(0);
		TArray<double> result = BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
		return result;
	}
	if (path == "funcString")
	{
		TArray<FString> ParamString = args.at(0);
		TArray<FString> result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
		return result;
	}
	return nlohmann::json();
}

void TbSimpleSimpleArrayInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string path = Name::getMemberName(propertyId);
	if (path == "propBool")
	{
		TArray<bool> PropBool = value.get<TArray<bool>>();
		BackendService->Execute_SetPropBool(BackendService.GetObject(), PropBool);
	}
	if (path == "propInt")
	{
		TArray<int32> PropInt = value.get<TArray<int32>>();
		BackendService->Execute_SetPropInt(BackendService.GetObject(), PropInt);
	}
	if (path == "propInt32")
	{
		TArray<int32> PropInt32 = value.get<TArray<int32>>();
		BackendService->Execute_SetPropInt32(BackendService.GetObject(), PropInt32);
	}
	if (path == "propInt64")
	{
		TArray<int64> PropInt64 = value.get<TArray<int64>>();
		BackendService->Execute_SetPropInt64(BackendService.GetObject(), PropInt64);
	}
	if (path == "propFloat")
	{
		TArray<float> PropFloat = value.get<TArray<float>>();
		BackendService->Execute_SetPropFloat(BackendService.GetObject(), PropFloat);
	}
	if (path == "propFloat32")
	{
		TArray<float> PropFloat32 = value.get<TArray<float>>();
		BackendService->Execute_SetPropFloat32(BackendService.GetObject(), PropFloat32);
	}
	if (path == "propFloat64")
	{
		TArray<double> PropFloat64 = value.get<TArray<double>>();
		BackendService->Execute_SetPropFloat64(BackendService.GetObject(), PropFloat64);
	}
	if (path == "propString")
	{
		TArray<FString> PropString = value.get<TArray<FString>>();
		BackendService->Execute_SetPropString(BackendService.GetObject(), PropString);
	}
}

nlohmann::json TbSimpleSimpleArrayInterfaceOLinkSource::olinkCollectProperties()
{
	return nlohmann::json::object({

		{"propBool", BackendService->Execute_GetPropBool(BackendService.GetObject())},
		{"propInt", BackendService->Execute_GetPropInt(BackendService.GetObject())},
		{"propInt32", BackendService->Execute_GetPropInt32(BackendService.GetObject())},
		{"propInt64", BackendService->Execute_GetPropInt64(BackendService.GetObject())},
		{"propFloat", BackendService->Execute_GetPropFloat(BackendService.GetObject())},
		{"propFloat32", BackendService->Execute_GetPropFloat32(BackendService.GetObject())},
		{"propFloat64", BackendService->Execute_GetPropFloat64(BackendService.GetObject())},
		{"propString", BackendService->Execute_GetPropString(BackendService.GetObject())}});
}