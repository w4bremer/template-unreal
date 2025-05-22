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
#include "TbRefInterfacesParentIfImplFixture.h"
#include "TbRefInterfaces/Implementation/TbRefInterfacesParentIf.h"
#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbRefInterfacesParentIfImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesParentIfImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbRefInterfacesParentIfImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbRefInterfacesParentIfImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbRefInterfacesParentIfImplHelper::LocalIfPropertyCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> TestValue = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
	// use different test value
	TestValue = nullptr;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InLocalIf, TestValue);
	if (TSharedPtr<FTbRefInterfacesParentIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetLocalIf(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefInterfacesParentIfImplHelper::ImportedIfPropertyCb(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	TScriptInterface<ITbRefInterfacesImportCounter> TestValue = TScriptInterface<ITbRefInterfacesImportCounter>();
	// use different test value
	TestValue = nullptr;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InImportedIf, TestValue);
	if (TSharedPtr<FTbRefInterfacesParentIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetImportedIf(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefInterfacesParentIfImplHelper::LocalIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InParam)
{
	// known test value
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = nullptr;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

void UTbRefInterfacesParentIfImplHelper::ImportedIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesImportCounter>& InParam)
{
	// known test value
	TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = nullptr;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

FTbRefInterfacesParentIfImplFixture::FTbRefInterfacesParentIfImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefInterfacesParentIfImplementation>();
	Helper = NewObject<UTbRefInterfacesParentIfImplHelper>();
}

FTbRefInterfacesParentIfImplFixture::~FTbRefInterfacesParentIfImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefInterfacesParentIf> FTbRefInterfacesParentIfImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbRefInterfacesParentIfImplHelper> FTbRefInterfacesParentIfImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbRefInterfacesParentIfImplFixture::GetGameInstance()
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

void FTbRefInterfacesParentIfImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbRefInterfacesParentIfImplHelper::SetParentFixture(TWeakPtr<FTbRefInterfacesParentIfImplFixture> /*InFixture*/)
{
}

void UTbRefInterfacesParentIfImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbRefInterfacesParentIfImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbRefInterfacesParentIfImplHelper::LocalIfPropertyCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf)
{
	(void)LocalIf;
}

void UTbRefInterfacesParentIfImplHelper::ImportedIfPropertyCb(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf)
{
	(void)ImportedIf;
}

void UTbRefInterfacesParentIfImplHelper::LocalIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	(void)Param;
}

void UTbRefInterfacesParentIfImplHelper::ImportedIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	(void)Param;
}
#endif // WITH_DEV_AUTOMATION_TESTS
