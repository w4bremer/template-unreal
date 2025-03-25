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
#include "TbRefInterfacesImportCounterImplFixture.h"
#include "TbRefInterfacesImport/Implementation/TbRefInterfacesImportCounter.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbRefInterfacesImportCounterImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesImportCounterImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbRefInterfacesImportCounterImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbRefInterfacesImportCounterImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

FTbRefInterfacesImportCounterImplFixture::FTbRefInterfacesImportCounterImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefInterfacesImportCounterImplementation>();
	Helper = NewObject<UTbRefInterfacesImportCounterImplHelper>();
}

FTbRefInterfacesImportCounterImplFixture::~FTbRefInterfacesImportCounterImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefInterfacesImportCounter> FTbRefInterfacesImportCounterImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbRefInterfacesImportCounterImplHelper> FTbRefInterfacesImportCounterImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbRefInterfacesImportCounterImplFixture::GetGameInstance()
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

void FTbRefInterfacesImportCounterImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbRefInterfacesImportCounterImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesImportCounterImplFixture> /*InFixture*/)
{
}

void UTbRefInterfacesImportCounterImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbRefInterfacesImportCounterImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
