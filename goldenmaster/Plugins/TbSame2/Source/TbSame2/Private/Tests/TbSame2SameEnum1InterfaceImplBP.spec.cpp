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

#include "TbSame2SameEnum1InterfaceImplBP.spec.h"
#include "Implementation/TbSame2SameEnum1Interface.h"
#include "TbSame2SameEnum1InterfaceImplBPFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameEnum1InterfaceBPBaseImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplBPFixture = MakeUnique<FTbSame2SameEnum1InterfaceImplBPFixture>();
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
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSame2SameEnum1InterfaceSignals->OnProp1Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSame2SameEnum1InterfaceBPBaseImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ImplBPFixture->GetImplementation()->Execute_SetProp1(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_Func1(ImplBPFixture->GetImplementation().GetObject(), ETbSame2Enum1::TS2E1_VALUE1);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSame2SameEnum1InterfaceSignals->OnSig1Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSame2SameEnum1InterfaceBPBaseImplHelper::Sig1SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		TbSame2SameEnum1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

void UTbSame2SameEnum1InterfaceBPBaseImplSpec::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetProp1(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum1InterfaceBPBaseImplSpec::Sig1SignalCb(ETbSame2Enum1 InParam1)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
