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
#include "TbRefInterfacesSimpleLocalIfOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbRefInterfaces/Generated/OLink/TbRefInterfacesSimpleLocalIfOLinkClient.h"
#include "TbRefInterfaces/Generated/OLink/TbRefInterfacesSimpleLocalIfOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace SimpleLocalIf
{
namespace OLink
{
namespace Tests
{
FTbRefInterfacesSimpleLocalIfOLinkFixture::FTbRefInterfacesSimpleLocalIfOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfOLinkClient>();
}

FTbRefInterfacesSimpleLocalIfOLinkFixture::~FTbRefInterfacesSimpleLocalIfOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> FTbRefInterfacesSimpleLocalIfOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbRefInterfacesSimpleLocalIfOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbRefInterfacesSimpleLocalIfOLinkAdapter* FTbRefInterfacesSimpleLocalIfOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfOLinkAdapter>();
}

UGameInstance* FTbRefInterfacesSimpleLocalIfOLinkFixture::GetGameInstance()
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

void FTbRefInterfacesSimpleLocalIfOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleLocalIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
