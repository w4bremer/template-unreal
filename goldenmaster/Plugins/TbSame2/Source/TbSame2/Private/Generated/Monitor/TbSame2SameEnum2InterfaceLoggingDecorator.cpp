
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
#include "Generated/Monitor/TbSame2SameEnum2InterfaceLoggingDecorator.h"
#include "Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2.trace.h"
#include "TbSame2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameEnum2InterfaceLoggingDecorator);
UTbSame2SameEnum2InterfaceLoggingDecorator::UTbSame2SameEnum2InterfaceLoggingDecorator()
	: UAbstractTbSame2SameEnum2Interface()
{
}

UTbSame2SameEnum2InterfaceLoggingDecorator::~UTbSame2SameEnum2InterfaceLoggingDecorator() = default;

void UTbSame2SameEnum2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(Collection));
#endif
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameEnum2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1(ETbSame2Enum1 Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute_BroadcastSig2(this, Param1, Param2);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp1_Implementation(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed(ETbSame2Enum2 InProp2)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp2_Implementation(ETbSame2Enum2 InProp2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func1_Implementation(ETbSame2Enum1 Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
