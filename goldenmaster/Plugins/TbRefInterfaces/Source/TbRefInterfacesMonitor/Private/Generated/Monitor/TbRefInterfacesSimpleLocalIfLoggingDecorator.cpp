

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
#include "TbRefInterfaces/Generated/Monitor/TbRefInterfacesSimpleLocalIfLoggingDecorator.h"
#include "TbRefInterfacesSettings.h"
#include "TbRefInterfaces.trace.h"
#include "TbRefInterfaces/Generated/TbRefInterfacesFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbRefInterfacesSimpleLocalIfLoggingDecorator);
UTbRefInterfacesSimpleLocalIfLoggingDecorator::UTbRefInterfacesSimpleLocalIfLoggingDecorator()
	: UAbstractTbRefInterfacesSimpleLocalIf()
{
}

UTbRefInterfacesSimpleLocalIfLoggingDecorator::~UTbRefInterfacesSimpleLocalIfLoggingDecorator() = default;

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbRefInterfacesSettings::GetITbRefInterfacesSimpleLocalIfForLogging(Collection));
}

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::setBackendService(TScriptInterface<ITbRefInterfacesSimpleLocalIf> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbRefInterfacesSimpleLocalIfSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefInterfacesSimpleLocalIf"));
		BackendSignals->OnIntPropertyChangedBP.RemoveDynamic(this, &UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntPropertyChanged);
		BackendSignals->OnIntSignalSignalBP.RemoveDynamic(this, &UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntSignal);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefInterfacesSimpleLocalIf is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbRefInterfacesSimpleLocalIfSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefInterfacesSimpleLocalIf"));
	// connect property changed signals or simple events
	BackendSignals->OnIntPropertyChangedBP.AddDynamic(this, &UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntPropertyChanged);
	BackendSignals->OnIntSignalSignalBP.AddDynamic(this, &UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntSignal);
	// populate service state to proxy
	IntProperty = BackendService->GetIntProperty();
}

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntSignal(int32 InParam)
{
	TbRefInterfacesSimpleLocalIfTracer::trace_signalIntSignal(InParam);
	_GetSignals()->BroadcastIntSignalSignal(InParam);
}

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::OnIntPropertyChanged(int32 InIntProperty)
{
	TbRefInterfacesSimpleLocalIfTracer::capture_state(BackendService.GetObject(), this);
	IntProperty = InIntProperty;
	_GetSignals()->BroadcastIntPropertyChanged(InIntProperty);
}

int32 UTbRefInterfacesSimpleLocalIfLoggingDecorator::GetIntProperty() const
{
	return BackendService->GetIntProperty();
}

void UTbRefInterfacesSimpleLocalIfLoggingDecorator::SetIntProperty(int32 InIntProperty)
{
	TbRefInterfacesSimpleLocalIfTracer::trace_callSetIntProperty(InIntProperty);
	BackendService->SetIntProperty(InIntProperty);
}

int32 UTbRefInterfacesSimpleLocalIfLoggingDecorator::IntMethod(int32 Param)
{
	TbRefInterfacesSimpleLocalIfTracer::trace_callIntMethod(Param);
	return BackendService->IntMethod(Param);
}
