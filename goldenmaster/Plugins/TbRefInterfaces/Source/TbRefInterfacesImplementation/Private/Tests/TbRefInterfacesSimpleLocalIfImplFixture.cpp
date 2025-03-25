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
#include "TbRefInterfacesSimpleLocalIfImplFixture.h"
#include "TbRefInterfaces/Implementation/TbRefInterfacesSimpleLocalIf.h"
#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbRefInterfacesSimpleLocalIfImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesSimpleLocalIfImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbRefInterfacesSimpleLocalIfImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbRefInterfacesSimpleLocalIfImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbRefInterfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb(int32 InIntProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
	if (TSharedPtr<FTbRefInterfacesSimpleLocalIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetIntProperty(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefInterfacesSimpleLocalIfImplHelper::IntSignalSignalCb(int32 InParam)
{
	// known test value
	int32 ParamTestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

FTbRefInterfacesSimpleLocalIfImplFixture::FTbRefInterfacesSimpleLocalIfImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfImplementation>();
	Helper = NewObject<UTbRefInterfacesSimpleLocalIfImplHelper>();
}

FTbRefInterfacesSimpleLocalIfImplFixture::~FTbRefInterfacesSimpleLocalIfImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> FTbRefInterfacesSimpleLocalIfImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbRefInterfacesSimpleLocalIfImplHelper> FTbRefInterfacesSimpleLocalIfImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbRefInterfacesSimpleLocalIfImplFixture::GetGameInstance()
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

void FTbRefInterfacesSimpleLocalIfImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbRefInterfacesSimpleLocalIfImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesSimpleLocalIfImplFixture> /*InFixture*/)
{
}

void UTbRefInterfacesSimpleLocalIfImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbRefInterfacesSimpleLocalIfImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbRefInterfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb(int32 IntProperty)
{
	(void)IntProperty;
}

void UTbRefInterfacesSimpleLocalIfImplHelper::IntSignalSignalCb(int32 Param)
{
	(void)Param;
}
#endif // WITH_DEV_AUTOMATION_TESTS
