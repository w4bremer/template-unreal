

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
#include "Testbed2/Generated/Monitor/Testbed2NestedStruct1InterfaceLoggingDecorator.h"
#include "Testbed2Settings.h"
#include "Testbed2.trace.h"
#include "Testbed2/Generated/Testbed2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct1InterfaceLoggingDecorator);
UTestbed2NestedStruct1InterfaceLoggingDecorator::UTestbed2NestedStruct1InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct1Interface()
{
}

UTestbed2NestedStruct1InterfaceLoggingDecorator::~UTestbed2NestedStruct1InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTestbed2Settings::GetITestbed2NestedStruct1InterfaceForLogging(Collection));
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct1Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct1Interface"));
		BackendSignals->OnProp1ChangedBP.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnSig1SignalBP.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1ChangedBP.AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnSig1SignalBP.AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_signalSig1(InParam1);
	_GetSignals()->BroadcastSig1Signal(InParam1);
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetSignals()->BroadcastProp1Changed(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::Func1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}
