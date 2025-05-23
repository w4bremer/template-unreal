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
#include "TbNamesNamEsOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace OLink
{
namespace Tests
{
FTbNamesNamEsOLinkFixture::FTbNamesNamEsOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkClient>();
}

FTbNamesNamEsOLinkFixture::~FTbNamesNamEsOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbNamesNamEsOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbNamesNamEsOLinkAdapter* FTbNamesNamEsOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkAdapter>();
}

UGameInstance* FTbNamesNamEsOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbNamesNamEsOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
