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

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArrayInterfaceMsgBusSpec, "Testbed1.StructArrayInterface.MsgBus", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArrayInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArrayInterfaceMsgBusSpec);

void UTestbed1StructArrayInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTestbed1StructArrayInterfaceMsgBusClient* MsgBusClient = Cast<UTestbed1StructArrayInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
				// use different test value
				TestValue = createTestFTestbed1StructBoolArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructBool>(); // default value
				ImplFixture->GetImplementation()->SetPropBool(TestValue);
			}
			else
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
				// use different test value
				TestValue = createTestFTestbed1StructIntArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructInt>(); // default value
				ImplFixture->GetImplementation()->SetPropInt(TestValue);
			}
			else
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
				// use different test value
				TestValue = createTestFTestbed1StructFloatArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructFloat>(); // default value
				ImplFixture->GetImplementation()->SetPropFloat(TestValue);
			}
			else
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
				// use different test value
				TestValue = createTestFTestbed1StructStringArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructString>(); // default value
				ImplFixture->GetImplementation()->SetPropString(TestValue);
			}
			else
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
				// use different test value
				TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

				// now set it to the default value
				TestValue = TArray<ETestbed1Enum0>(); // default value
				ImplFixture->GetImplementation()->SetPropEnum(TestValue);
			}
			else
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(TArray<FTestbed1StructBool>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(TArray<FTestbed1StructInt>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(TArray<FTestbed1StructFloat>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(TArray<FTestbed1StructString>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncEnum(TArray<ETestbed1Enum0>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InParamBool)
			{
			// known test value
			TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InParamInt)
			{
			// known test value
			TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InParamFloat)
			{
			// known test value
			TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InParamString)
			{
			// known test value
			TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigEnumSignal.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InParamEnum)
			{
			// known test value
			TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
			ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		Testbed1StructArrayInterfaceSignals->BroadcastSigEnumSignal(ParamEnumTestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
