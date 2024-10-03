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

#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLinkAdapter.h"
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
#include "Testbed2NestedStruct3InterfaceOLinkSource.h"

using namespace ApiGear::ObjectLink;
UTestbed2NestedStruct3InterfaceOLinkAdapter::UTestbed2NestedStruct3InterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed2NestedStruct3InterfaceOLinkSource>())
{
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp3Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct3Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed2NestedStruct3Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp3Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig3);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Source->OnSig1(Param1);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Source->OnSig2(Param1, Param2);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Source->OnSig3(Param1, Param2, Param3);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Source->OnProp1Changed(InProp1);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Source->OnProp2Changed(InProp2);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
	Source->OnProp3Changed(InProp3);
}

void UTestbed2NestedStruct3InterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
