

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
#include "Counter/Generated/Monitor/CounterCounterLoggingDecorator.h"
#include "CounterSettings.h"
#include "Counter.trace.h"
#include "Counter/Generated/CounterFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogCounterCounterLoggingDecorator);
UCounterCounterLoggingDecorator::UCounterCounterLoggingDecorator()
	: UAbstractCounterCounter()
{
}

UCounterCounterLoggingDecorator::~UCounterCounterLoggingDecorator() = default;

void UCounterCounterLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UCounterSettings::GetICounterCounterForLogging(Collection));
}

void UCounterCounterLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UCounterCounterLoggingDecorator::setBackendService(TScriptInterface<ICounterCounter> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UCounterCounterSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		BackendSignals->OnVectorChangedBP.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnVectorChanged);
		BackendSignals->OnExternVectorChangedBP.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorChanged);
		BackendSignals->OnVectorArrayChangedBP.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnVectorArrayChanged);
		BackendSignals->OnExternVectorArrayChangedBP.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorArrayChanged);
		BackendSignals->OnValueChangedSignalBP.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnValueChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
	// connect property changed signals or simple events
	BackendSignals->OnVectorChangedBP.AddDynamic(this, &UCounterCounterLoggingDecorator::OnVectorChanged);
	BackendSignals->OnExternVectorChangedBP.AddDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorChanged);
	BackendSignals->OnVectorArrayChangedBP.AddDynamic(this, &UCounterCounterLoggingDecorator::OnVectorArrayChanged);
	BackendSignals->OnExternVectorArrayChangedBP.AddDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorArrayChanged);
	BackendSignals->OnValueChangedSignalBP.AddDynamic(this, &UCounterCounterLoggingDecorator::OnValueChanged);
	// populate service state to proxy
	Vector = BackendService->GetVector();
	ExternVector = BackendService->GetExternVector();
	VectorArray = BackendService->GetVectorArray();
	ExternVectorArray = BackendService->GetExternVectorArray();
}

void UCounterCounterLoggingDecorator::OnValueChanged(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::trace_signalValueChanged(InVector, InExternVector, InVectorArray, InExternVectorArray);
	_GetSignals()->BroadcastValueChangedSignal(InVector, InExternVector, InVectorArray, InExternVectorArray);
}

void UCounterCounterLoggingDecorator::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	Vector = InVector;
	_GetSignals()->BroadcastVectorChanged(InVector);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::GetVector() const
{
	return BackendService->GetVector();
}

void UCounterCounterLoggingDecorator::SetVector(const FCustomTypesVector3D& InVector)
{
	CounterCounterTracer::trace_callSetVector(InVector);
	BackendService->SetVector(InVector);
}

void UCounterCounterLoggingDecorator::OnExternVectorChanged(const FVector& InExternVector)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVector = InExternVector;
	_GetSignals()->BroadcastExternVectorChanged(InExternVector);
}

FVector UCounterCounterLoggingDecorator::GetExternVector() const
{
	return BackendService->GetExternVector();
}

void UCounterCounterLoggingDecorator::SetExternVector(const FVector& InExternVector)
{
	CounterCounterTracer::trace_callSetExternVector(InExternVector);
	BackendService->SetExternVector(InExternVector);
}

void UCounterCounterLoggingDecorator::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	VectorArray = InVectorArray;
	_GetSignals()->BroadcastVectorArrayChanged(InVectorArray);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::GetVectorArray() const
{
	return BackendService->GetVectorArray();
}

void UCounterCounterLoggingDecorator::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	CounterCounterTracer::trace_callSetVectorArray(InVectorArray);
	BackendService->SetVectorArray(InVectorArray);
}

void UCounterCounterLoggingDecorator::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVectorArray = InExternVectorArray;
	_GetSignals()->BroadcastExternVectorArrayChanged(InExternVectorArray);
}

TArray<FVector> UCounterCounterLoggingDecorator::GetExternVectorArray() const
{
	return BackendService->GetExternVectorArray();
}

void UCounterCounterLoggingDecorator::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::trace_callSetExternVectorArray(InExternVectorArray);
	BackendService->SetExternVectorArray(InExternVectorArray);
}

FVector UCounterCounterLoggingDecorator::Increment(const FVector& Vec)
{
	CounterCounterTracer::trace_callIncrement(Vec);
	return BackendService->Increment(Vec);
}

TArray<FVector> UCounterCounterLoggingDecorator::IncrementArray(const TArray<FVector>& Vec)
{
	CounterCounterTracer::trace_callIncrementArray(Vec);
	return BackendService->IncrementArray(Vec);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::Decrement(const FCustomTypesVector3D& Vec)
{
	CounterCounterTracer::trace_callDecrement(Vec);
	return BackendService->Decrement(Vec);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::DecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	CounterCounterTracer::trace_callDecrementArray(Vec);
	return BackendService->DecrementArray(Vec);
}
