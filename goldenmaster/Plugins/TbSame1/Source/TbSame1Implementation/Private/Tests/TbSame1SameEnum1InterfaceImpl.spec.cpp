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

#include "TbSame1SameEnum1InterfaceImpl.spec.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "TbSame1SameEnum1InterfaceImplFixture.h"
#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameEnum1InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbSame1SameEnum1InterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
			{
			ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
			// use different test value
			TestValue = ETbSame1Enum1::TS1E1_VALUE2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum1InterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum1InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(ETbSame1Enum1::TS1E1_VALUE1);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum1InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](ETbSame1Enum1 InParam1)
			{
			// known test value
			ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		TbSame1SameEnum1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum1InterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum1InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		TbSame1SameEnum1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

void UTbSame1SameEnum1InterfaceImplSpec::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum1InterfaceImplSpec::Sig1SignalCb(ETbSame1Enum1 InParam1)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
