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

#include "Testbed2NestedStruct1InterfaceImplBP.spec.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2NestedStruct1InterfaceImplBPFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct1InterfaceBPBaseImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplBPFixture = MakeUnique<FTestbed2NestedStruct1InterfaceImplBPFixture>();
		TestTrue("Check for valid ImplBPFixture", ImplBPFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplBPFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplBPFixture->GetHelper().IsValid());
		ImplBPFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplBPFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct1InterfaceSignals* Testbed2NestedStruct1InterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		Testbed2NestedStruct1InterfaceSignals->OnProp1Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplBPFixture->GetImplementation()->Execute_SetProp1(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_Func1(ImplBPFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1());
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct1InterfaceSignals* Testbed2NestedStruct1InterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		Testbed2NestedStruct1InterfaceSignals->OnSig1Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

void UTestbed2NestedStruct1InterfaceBPBaseImplSpec::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct1InterfaceBPBaseImplSpec::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
