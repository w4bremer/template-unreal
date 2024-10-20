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

#include "Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "Testbed1StructInterfaceOLinkSource.h"

using namespace ApiGear::ObjectLink;
UTestbed1StructInterfaceOLinkAdapter::UTestbed1StructInterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed1StructInterfaceOLinkSource>())
{
}

void UTestbed1StructInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed1StructInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface HmiFrontDisplay is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigBool(const FTestbed1StructBool& ParamBool)
{
	Source->OnSigBool(ParamBool);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigInt(const FTestbed1StructInt& ParamInt)
{
	Source->OnSigInt(ParamInt);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	Source->OnSigFloat(ParamFloat);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigString(const FTestbed1StructString& ParamString)
{
	Source->OnSigString(ParamString);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	Source->OnPropBoolChanged(InPropBool);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	Source->OnPropFloatChanged(InPropFloat);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	Source->OnPropStringChanged(InPropString);
}

void UTestbed1StructInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	check(InHost);
	Source->setOLinkHost(InHost.Get());

	if (Registry)
	{
		Registry->removeSource(Source->olinkObjectName());
	}
	Registry = InHost->GetOLinkRegistry();
	// register source to host registry
	Registry->addSource(Source);
}
