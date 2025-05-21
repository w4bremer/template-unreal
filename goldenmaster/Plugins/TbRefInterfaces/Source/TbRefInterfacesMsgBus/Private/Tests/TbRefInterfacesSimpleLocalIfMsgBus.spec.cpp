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

#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfaces/Implementation/TbRefInterfacesSimpleLocalIf.h"
#include "TbRefInterfacesSimpleLocalIfMsgBusFixture.h"
#include "TbRefInterfaces/Generated/MsgBus/TbRefInterfacesSimpleLocalIfMsgBusClient.h"
#include "TbRefInterfaces/Generated/MsgBus/TbRefInterfacesSimpleLocalIfMsgBusAdapter.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace SimpleLocalIf
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefInterfacesSimpleLocalIfMsgBusSpec, "TbRefInterfaces.SimpleLocalIf.MsgBus", TbRefInterfacesTestFilterMask);

TUniquePtr<FTbRefInterfacesSimpleLocalIfMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesSimpleLocalIfMsgBusSpec);

void UTbRefInterfacesSimpleLocalIfMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefInterfacesSimpleLocalIfMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbRefInterfacesSimpleLocalIfMsgBusClient* MsgBusClient = Cast<UTbRefInterfacesSimpleLocalIfMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

	LatentIt("Property.IntProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfImplementation>();
		service->SetIntProperty(TestValue);
	});

	LatentIt("Property.IntProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		UTbRefInterfacesSimpleLocalIfSignals* TbRefInterfacesSimpleLocalIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesSimpleLocalIfSignals->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

				// now set it to the default value
				TestValue = 0; // default value
				ImplFixture->GetImplementation()->SetIntProperty(TestValue);
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesSimpleLocalIfImplementation>();
		service->SetIntProperty(TestValue);
	});

	LatentIt("Operation.IntMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->IntMethod(0);
			TestDone.Execute();
		});
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
}
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleLocalIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS
