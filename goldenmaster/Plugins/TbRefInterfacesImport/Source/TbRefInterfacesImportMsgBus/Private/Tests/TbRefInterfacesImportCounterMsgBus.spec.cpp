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

#include "TbRefInterfacesImport/Tests/TbRefInterfacesImportTestsCommon.h"
#include "TbRefInterfacesImport/Implementation/TbRefInterfacesImportCounter.h"
#include "TbRefInterfacesImportCounterMsgBusFixture.h"
#include "TbRefInterfacesImport/Generated/MsgBus/TbRefInterfacesImportCounterMsgBusClient.h"
#include "TbRefInterfacesImport/Generated/MsgBus/TbRefInterfacesImportCounterMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfacesImport
{
namespace Counter
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefInterfacesImportCounterMsgBusSpec, "TbRefInterfacesImport.Counter.MsgBus", TbRefInterfacesImportTestFilterMask);

TUniquePtr<FTbRefInterfacesImportCounterMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefInterfacesImportCounterMsgBusSpec);

void UTbRefInterfacesImportCounterMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefInterfacesImportCounterMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefInterfacesImportCounterImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbRefInterfacesImportCounterMsgBusClient* MsgBusClient = Cast<UTbRefInterfacesImportCounterMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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
}
} // namespace Tests
} // namespace MsgBus
} // namespace Counter
} // namespace TbRefInterfacesImport

#endif // WITH_DEV_AUTOMATION_TESTS
