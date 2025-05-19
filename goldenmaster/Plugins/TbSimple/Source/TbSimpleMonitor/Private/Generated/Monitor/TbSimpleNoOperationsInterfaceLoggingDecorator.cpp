

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
#include "TbSimple/Generated/Monitor/TbSimpleNoOperationsInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoOperationsInterfaceLoggingDecorator);
UTbSimpleNoOperationsInterfaceLoggingDecorator::UTbSimpleNoOperationsInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoOperationsInterface()
{
}

UTbSimpleNoOperationsInterfaceLoggingDecorator::~UTbSimpleNoOperationsInterfaceLoggingDecorator() = default;

void UTbSimpleNoOperationsInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleNoOperationsInterfaceForLogging(Collection));
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleNoOperationsInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoOperationsInterface"));
		BackendSignals->OnPropBoolChangedBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChangedBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnSigVoidSignalBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
		BackendSignals->OnSigBoolSignalBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoOperationsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoOperationsInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChangedBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChangedBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnSigVoidSignalBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
	BackendSignals->OnSigBoolSignalBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	// populate service state to proxy
	bPropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigVoid();
	_GetSignals()->BroadcastSigVoidSignal();
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool(bool bInParamBool)
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigBool(bInParamBool);
	_GetSignals()->BroadcastSigBoolSignal(bInParamBool);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleNoOperationsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	_GetSignals()->BroadcastPropBoolChanged(bInPropBool);
}

bool UTbSimpleNoOperationsInterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::SetPropBool(bool bInPropBool)
{
	TbSimpleNoOperationsInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->SetPropBool(bInPropBool);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleNoOperationsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetSignals()->BroadcastPropIntChanged(InPropInt);
}

int32 UTbSimpleNoOperationsInterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::SetPropInt(int32 InPropInt)
{
	TbSimpleNoOperationsInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}
