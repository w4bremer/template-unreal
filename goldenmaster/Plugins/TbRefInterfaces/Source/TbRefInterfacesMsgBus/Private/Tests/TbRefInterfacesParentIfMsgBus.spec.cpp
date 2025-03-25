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
#include "TbRefInterfaces/Implementation/TbRefInterfacesParentIf.h"
#include "TbRefInterfacesParentIfMsgBusFixture.h"
#include "TbRefInterfaces/Generated/MsgBus/TbRefInterfacesParentIfMsgBusClient.h"
#include "TbRefInterfaces/Generated/MsgBus/TbRefInterfacesParentIfMsgBusAdapter.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace ParentIf
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefInterfacesParentIfMsgBusSpec, "TbRefInterfaces.ParentIf.MsgBus", TbRefInterfacesTestFilterMask);

TUniquePtr<FTbRefInterfacesParentIfMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesParentIfMsgBusSpec);

void UTbRefInterfacesParentIfMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefInterfacesParentIfMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesParentIfImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbRefInterfacesParentIfMsgBusClient* MsgBusClient = Cast<UTbRefInterfacesParentIfMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

	LatentIt("Operation.LocalIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->LocalIfMethod(TScriptInterface<ITbRefInterfacesSimpleLocalIf>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.ImportedIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->ImportedIfMethod(TScriptInterface<ITbRefInterfacesImportCounter>());
			TestDone.Execute();
		});
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
}
} // namespace Tests
} // namespace MsgBus
} // namespace ParentIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS
