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

#include "TbRefInterfaces/Implementation/TbRefInterfacesParentIf.h"
#include "TbRefInterfacesParentIfImplFixture.h"
#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbRefInterfacesParentIfImplSpec, "TbRefInterfaces.ParentIf.Impl", TbRefInterfacesTestFilterMask);

TSharedPtr<FTbRefInterfacesParentIfImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesParentIfImplSpec);

void UTbRefInterfacesParentIfImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbRefInterfacesParentIfImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.LocalIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbRefInterfacesSimpleLocalIf> TestValue = TScriptInterface<ITbRefInterfacesSimpleLocalIf>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetLocalIf(), TestValue);
	});

	It("Property.ImportedIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbRefInterfacesImportCounter> TestValue = TScriptInterface<ITbRefInterfacesImportCounter>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetImportedIf(), TestValue);
	});

	It("Operation.LocalIfMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->LocalIfMethod(TScriptInterface<ITbRefInterfacesSimpleLocalIf>());
	});

	It("Operation.ImportedIfMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->ImportedIfMethod(TScriptInterface<ITbRefInterfacesImportCounter>());
	});

	LatentIt("Signal.LocalIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesParentIfSignals->OnLocalIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
		TbRefInterfacesParentIfSignals->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.LocalIfSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesParentIfSignals->OnLocalIfSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefInterfacesParentIfImplHelper::LocalIfSignalSignalCb);

		// use different test value
		TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
		TbRefInterfacesParentIfSignals->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesParentIfSignals->OnImportedIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefInterfacesImportCounter>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = TScriptInterface<ITbRefInterfacesImportCounter>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = TScriptInterface<ITbRefInterfacesImportCounter>();
		TbRefInterfacesParentIfSignals->BroadcastImportedIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesParentIfSignals->OnImportedIfSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefInterfacesParentIfImplHelper::ImportedIfSignalSignalCb);

		// use different test value
		TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = TScriptInterface<ITbRefInterfacesImportCounter>();
		TbRefInterfacesParentIfSignals->BroadcastImportedIfSignalSignal(ParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
