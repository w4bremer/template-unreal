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

#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkAdapter.h"
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
#include "TbSimpleNoPropertiesInterfaceOLinkSource.h"

using namespace ApiGear::ObjectLink;
UTbSimpleNoPropertiesInterfaceOLinkAdapter::UTbSimpleNoPropertiesInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleNoPropertiesInterfaceOLinkSource>())
{
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoPropertiesInterface"));
		BackendSignals->OnSigVoidSignal.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigVoid);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoPropertiesInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleNoPropertiesInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnSigVoidSignal.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigVoid);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigBool);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigVoid()
{
	Source->OnSigVoid();
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::OnSigBool(bool bParamBool)
{
	Source->OnSigBool(bParamBool);
}

void UTbSimpleNoPropertiesInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
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
