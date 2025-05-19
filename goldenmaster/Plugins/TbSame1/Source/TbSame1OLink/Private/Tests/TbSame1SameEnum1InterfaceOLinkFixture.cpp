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
#include "TbSame1SameEnum1InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSame1/Generated/OLink/TbSame1SameEnum1InterfaceOLinkClient.h"
#include "TbSame1/Generated/OLink/TbSame1SameEnum1InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace OLink
{
namespace Tests
{
FTbSame1SameEnum1InterfaceOLinkFixture::FTbSame1SameEnum1InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceOLinkClient>();
}

FTbSame1SameEnum1InterfaceOLinkFixture::~FTbSame1SameEnum1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum1Interface> FTbSame1SameEnum1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameEnum1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameEnum1InterfaceOLinkAdapter* FTbSame1SameEnum1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceOLinkAdapter>();
}

UGameInstance* FTbSame1SameEnum1InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame1SameEnum1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SameEnum1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
