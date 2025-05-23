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

#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"
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
#include "Testbed2ManyParamInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTestbed2ManyParamInterfaceOLinkAdapter::UTestbed2ManyParamInterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed2ManyParamInterfaceOLinkSource>())
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed2ManyParamInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2ManyParamInterface"));
		if (OnProp1ChangedHandle.IsValid())
		{
			BackendSignals->OnProp1Changed.Remove(OnProp1ChangedHandle);
			OnProp1ChangedHandle.Reset();
		}
		if (OnProp2ChangedHandle.IsValid())
		{
			BackendSignals->OnProp2Changed.Remove(OnProp2ChangedHandle);
			OnProp2ChangedHandle.Reset();
		}
		if (OnProp3ChangedHandle.IsValid())
		{
			BackendSignals->OnProp3Changed.Remove(OnProp3ChangedHandle);
			OnProp3ChangedHandle.Reset();
		}
		if (OnProp4ChangedHandle.IsValid())
		{
			BackendSignals->OnProp4Changed.Remove(OnProp4ChangedHandle);
			OnProp4ChangedHandle.Reset();
		}
		if (OnSig1SignalHandle.IsValid())
		{
			BackendSignals->OnSig1Signal.Remove(OnSig1SignalHandle);
			OnSig1SignalHandle.Reset();
		}
		if (OnSig2SignalHandle.IsValid())
		{
			BackendSignals->OnSig2Signal.Remove(OnSig2SignalHandle);
			OnSig2SignalHandle.Reset();
		}
		if (OnSig3SignalHandle.IsValid())
		{
			BackendSignals->OnSig3Signal.Remove(OnSig3SignalHandle);
			OnSig3SignalHandle.Reset();
		}
		if (OnSig4SignalHandle.IsValid())
		{
			BackendSignals->OnSig4Signal.Remove(OnSig4SignalHandle);
			OnSig4SignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2ManyParamInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed2ManyParamInterface"));
	// connect property changed signals or simple events
	OnProp1ChangedHandle = BackendSignals->OnProp1Changed.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnProp1Changed);
	OnProp2ChangedHandle = BackendSignals->OnProp2Changed.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnProp2Changed);
	OnProp3ChangedHandle = BackendSignals->OnProp3Changed.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnProp3Changed);
	OnProp4ChangedHandle = BackendSignals->OnProp4Changed.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnProp4Changed);
	OnSig1SignalHandle = BackendSignals->OnSig1Signal.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnSig1);
	OnSig2SignalHandle = BackendSignals->OnSig2Signal.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnSig2);
	OnSig3SignalHandle = BackendSignals->OnSig3Signal.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnSig3);
	OnSig4SignalHandle = BackendSignals->OnSig4Signal.AddUObject(this, &UTestbed2ManyParamInterfaceOLinkAdapter::OnSig4);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig1(int32 Param1)
{
	Source->OnSig1(Param1);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig2(int32 Param1, int32 Param2)
{
	Source->OnSig2(Param1, Param2);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig3(int32 Param1, int32 Param2, int32 Param3)
{
	Source->OnSig3(Param1, Param2, Param3);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Source->OnSig4(Param1, Param2, Param3, Param4);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp1Changed(int32 InProp1)
{
	Source->OnProp1Changed(InProp1);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp2Changed(int32 InProp2)
{
	Source->OnProp2Changed(InProp2);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp3Changed(int32 InProp3)
{
	Source->OnProp3Changed(InProp3);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp4Changed(int32 InProp4)
{
	Source->OnProp4Changed(InProp4);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)

UTestbed2ManyParamInterfaceOLinkAdapter::UTestbed2ManyParamInterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed2ManyParamInterfaceOLinkSource>())
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2ManyParamInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed2ManyParamInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig1(int32 Param1)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig2(int32 Param1, int32 Param2)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig3(int32 Param1, int32 Param2, int32 Param3)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp1Changed(int32 InProp1)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp2Changed(int32 InProp2)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp3Changed(int32 InProp3)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::OnProp4Changed(int32 InProp4)
{
}

void UTestbed2ManyParamInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
