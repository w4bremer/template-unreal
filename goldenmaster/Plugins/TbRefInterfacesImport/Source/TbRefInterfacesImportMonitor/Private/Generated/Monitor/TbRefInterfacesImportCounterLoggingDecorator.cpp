

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
#include "TbRefInterfacesImport/Generated/Monitor/TbRefInterfacesImportCounterLoggingDecorator.h"
#include "TbRefInterfacesImportSettings.h"
#include "TbRefInterfacesImport.trace.h"
#include "TbRefInterfacesImport/Generated/TbRefInterfacesImportFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbRefInterfacesImportCounterLoggingDecorator);
UTbRefInterfacesImportCounterLoggingDecorator::UTbRefInterfacesImportCounterLoggingDecorator()
	: UAbstractTbRefInterfacesImportCounter()
{
}

UTbRefInterfacesImportCounterLoggingDecorator::~UTbRefInterfacesImportCounterLoggingDecorator() = default;

void UTbRefInterfacesImportCounterLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	// setBackendService(UTbRefInterfacesImportSettings::GetITbRefInterfacesImportCounterForLogging(Collection));
}

void UTbRefInterfacesImportCounterLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbRefInterfacesImportCounterLoggingDecorator::setBackendService(TScriptInterface<ITbRefInterfacesImportCounter> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefInterfacesImportCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	// populate service state to proxy
}
