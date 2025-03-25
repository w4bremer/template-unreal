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

#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "TbRefInterfacesParentIfOLinkFixture.h"
#include "TbRefInterfaces/Implementation/TbRefInterfacesParentIf.h"
#include "TbRefInterfaces/Generated/OLink/TbRefInterfacesParentIfOLinkClient.h"
#include "TbRefInterfaces/Generated/OLink/TbRefInterfacesParentIfOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbRefInterfaces/Tests/TbRefInterfacesTestsCommon.h"
#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace ParentIf
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefInterfacesParentIfOLinkSpec, "TbRefInterfaces.ParentIf.OLink", TbRefInterfacesTestFilterMask);

TUniquePtr<FTbRefInterfacesParentIfOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesParentIfOLinkSpec);

void UTbRefInterfacesParentIfOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefInterfacesParentIfOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesParentIfImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbRefInterfacesParentIfOLinkClient* OLinkClient = Cast<UTbRefInterfacesParentIfOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(GetTransientPackage(), "TestingConnection");
		ImplFixture->Connection.GetObject()->AddToRoot();
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		if (ImplFixture->Connection && IsValid(ImplFixture->Connection.GetObject()))
		{
			ImplFixture->Connection->Disconnect();
			ImplFixture->Connection.GetObject()->RemoveFromRoot();
		}
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
			TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = createTestTScriptInterface<ITbRefInterfacesSimpleLocalIf>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefInterfacesSimpleLocalIf> ParamTestValue = createTestTScriptInterface<ITbRefInterfacesSimpleLocalIf>();
		TbRefInterfacesParentIfSignals->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefInterfacesParentIfSignals* TbRefInterfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefInterfacesParentIfSignals->OnImportedIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefInterfacesImportCounter>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = createTestTScriptInterface<ITbRefInterfacesImportCounter>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefInterfacesImportCounter> ParamTestValue = createTestTScriptInterface<ITbRefInterfacesImportCounter>();
		TbRefInterfacesParentIfSignals->BroadcastImportedIfSignalSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace ParentIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
