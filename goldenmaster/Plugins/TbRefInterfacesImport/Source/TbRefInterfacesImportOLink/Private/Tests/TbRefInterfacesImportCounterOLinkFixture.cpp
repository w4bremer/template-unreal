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
#include "TbRefInterfacesImportCounterOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbRefInterfacesImport/Generated/OLink/TbRefInterfacesImportCounterOLinkClient.h"
#include "TbRefInterfacesImport/Generated/OLink/TbRefInterfacesImportCounterOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfacesImport
{
namespace Counter
{
namespace OLink
{
namespace Tests
{
FTbRefInterfacesImportCounterOLinkFixture::FTbRefInterfacesImportCounterOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefInterfacesImportCounterOLinkClient>();
}

FTbRefInterfacesImportCounterOLinkFixture::~FTbRefInterfacesImportCounterOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefInterfacesImportCounter> FTbRefInterfacesImportCounterOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbRefInterfacesImportCounterOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbRefInterfacesImportCounterOLinkAdapter* FTbRefInterfacesImportCounterOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefInterfacesImportCounterOLinkAdapter>();
}

UGameInstance* FTbRefInterfacesImportCounterOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbRefInterfacesImportCounterOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace Counter
} // namespace TbRefInterfacesImport

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
