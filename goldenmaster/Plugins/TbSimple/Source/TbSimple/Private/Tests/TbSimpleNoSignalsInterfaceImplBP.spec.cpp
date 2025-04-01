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

#include "TbSimpleNoSignalsInterfaceImplBP.spec.h"
#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterfaceImplBPFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoSignalsInterfaceBPBaseImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplBPFixture = MakeUnique<FTbSimpleNoSignalsInterfaceImplBPFixture>();
		TestTrue("Check for valid ImplBPFixture", ImplBPFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplBPFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplBPFixture->GetHelper().IsValid());
		ImplBPFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplBPFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoSignalsInterfaceSignals* TbSimpleNoSignalsInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleNoSignalsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = true;
		ImplBPFixture->GetImplementation()->Execute_SetPropBool(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoSignalsInterfaceSignals* TbSimpleNoSignalsInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleNoSignalsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplBPFixture->GetImplementation()->Execute_SetPropInt(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.FuncVoid", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncVoid(ImplBPFixture->GetImplementation().GetObject());
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncBool(ImplBPFixture->GetImplementation().GetObject(), false);
	});
}

void UTbSimpleNoSignalsInterfaceBPBaseImplSpec::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoSignalsInterfaceBPBaseImplSpec::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
