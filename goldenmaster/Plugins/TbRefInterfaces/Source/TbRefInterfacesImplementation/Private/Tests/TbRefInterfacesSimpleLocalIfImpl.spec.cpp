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

#include "TbRefInterfaces/Implementation/TbRefInterfacesSimpleLocalIf.h"
#include "TbRefInterfacesSimpleLocalIfImplFixture.h"
#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbRefInterfacesSimpleLocalIfImplSpec, "TbRefInterfaces.SimpleLocalIf.Impl", TbRefInterfacesTestFilterMask);

TSharedPtr<FTbRefInterfacesSimpleLocalIfImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesSimpleLocalIfImplSpec);

void UTbRefInterfacesSimpleLocalIfImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbRefInterfacesSimpleLocalIfImplFixture>();
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

	It("Property.IntProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
	});

	LatentIt("Property.IntProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesSimpleLocalIfSignals->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetIntProperty(TestValue);
	});

	LatentIt("Property.IntProperty.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesSimpleLocalIfSignals->OnIntPropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefInterfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetIntProperty(TestValue);
	});

	It("Operation.IntMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->IntMethod(0);
	});

	LatentIt("Signal.IntSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesSimpleLocalIfSignals->OnIntSignalSignal.AddLambda([this, TestDone](int32 InParam)
			{
			// known test value
			int32 ParamTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamTestValue = 1;
		TbRefInterfacesSimpleLocalIfSignals->BroadcastIntSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.IntSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesSimpleLocalIfSignals->OnIntSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefInterfacesSimpleLocalIfImplHelper::IntSignalSignalCb);

		// use different test value
		int32 ParamTestValue = 1;
		TbRefInterfacesSimpleLocalIfSignals->BroadcastIntSignalSignal(ParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
