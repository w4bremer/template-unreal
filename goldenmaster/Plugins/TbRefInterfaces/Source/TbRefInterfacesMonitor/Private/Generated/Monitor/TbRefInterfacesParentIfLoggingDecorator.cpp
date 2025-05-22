

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
#include "TbRefInterfaces/Generated/Monitor/TbRefInterfacesParentIfLoggingDecorator.h"
#include "TbRefInterfacesSettings.h"
#include "TbRefInterfaces.trace.h"
#include "TbRefInterfaces/Generated/TbRefInterfacesFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbRefInterfacesParentIfLoggingDecorator);
UTbRefInterfacesParentIfLoggingDecorator::UTbRefInterfacesParentIfLoggingDecorator()
	: UAbstractTbRefInterfacesParentIf()
{
}

UTbRefInterfacesParentIfLoggingDecorator::~UTbRefInterfacesParentIfLoggingDecorator() = default;

void UTbRefInterfacesParentIfLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	// setBackendService(UTbRefInterfacesSettings::GetITbRefInterfacesParentIfForLogging(Collection));
}

void UTbRefInterfacesParentIfLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbRefInterfacesParentIfLoggingDecorator::setBackendService(TScriptInterface<ITbRefInterfacesParentIf> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbRefInterfacesParentIfSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefInterfacesParentIf"));
		BackendSignals->OnLocalIfChangedBP.RemoveDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfChanged);
		BackendSignals->OnImportedIfChangedBP.RemoveDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfChanged);
		BackendSignals->OnLocalIfSignalSignalBP.RemoveDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfSignal);
		BackendSignals->OnImportedIfSignalSignalBP.RemoveDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfSignal);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefInterfacesParentIf is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbRefInterfacesParentIfSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefInterfacesParentIf"));
	// connect property changed signals or simple events
	BackendSignals->OnLocalIfChangedBP.AddDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfChanged);
	BackendSignals->OnImportedIfChangedBP.AddDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfChanged);
	BackendSignals->OnLocalIfSignalSignalBP.AddDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfSignal);
	BackendSignals->OnImportedIfSignalSignalBP.AddDynamic(this, &UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfSignal);
	// populate service state to proxy
	LocalIf = BackendService->GetLocalIf();
	ImportedIf = BackendService->GetImportedIf();
}

void UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InParam)
{
	TbRefInterfacesParentIfTracer::trace_signalLocalIfSignal(InParam);
	_GetSignals()->BroadcastLocalIfSignalSignal(InParam);
}

void UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& InParam)
{
	TbRefInterfacesParentIfTracer::trace_signalImportedIfSignal(InParam);
	_GetSignals()->BroadcastImportedIfSignalSignal(InParam);
}

void UTbRefInterfacesParentIfLoggingDecorator::OnLocalIfChanged(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	TbRefInterfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	LocalIf = InLocalIf;
	_GetSignals()->BroadcastLocalIfChanged(InLocalIf);
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> UTbRefInterfacesParentIfLoggingDecorator::GetLocalIf() const
{
	return BackendService->GetLocalIf();
}

void UTbRefInterfacesParentIfLoggingDecorator::SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	TbRefInterfacesParentIfTracer::trace_callSetLocalIf(InLocalIf);
	BackendService->SetLocalIf(InLocalIf);
}

void UTbRefInterfacesParentIfLoggingDecorator::OnImportedIfChanged(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	TbRefInterfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	ImportedIf = InImportedIf;
	_GetSignals()->BroadcastImportedIfChanged(InImportedIf);
}

TScriptInterface<ITbRefInterfacesImportCounter> UTbRefInterfacesParentIfLoggingDecorator::GetImportedIf() const
{
	return BackendService->GetImportedIf();
}

void UTbRefInterfacesParentIfLoggingDecorator::SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	TbRefInterfacesParentIfTracer::trace_callSetImportedIf(InImportedIf);
	BackendService->SetImportedIf(InImportedIf);
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> UTbRefInterfacesParentIfLoggingDecorator::LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	TbRefInterfacesParentIfTracer::trace_callLocalIfMethod(Param);
	return BackendService->LocalIfMethod(Param);
}

TScriptInterface<ITbRefInterfacesImportCounter> UTbRefInterfacesParentIfLoggingDecorator::ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	TbRefInterfacesParentIfTracer::trace_callImportedIfMethod(Param);
	return BackendService->ImportedIfMethod(Param);
}
