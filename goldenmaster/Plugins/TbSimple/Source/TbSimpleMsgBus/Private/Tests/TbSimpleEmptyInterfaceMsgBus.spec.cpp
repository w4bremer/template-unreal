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

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "TbSimpleEmptyInterfaceMsgBusFixture.h"
#include "TbSimple/Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleEmptyInterfaceMsgBusSpec, "TbSimple.EmptyInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleEmptyInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleEmptyInterfaceMsgBusSpec);

void UTbSimpleEmptyInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleEmptyInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSimpleEmptyInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleEmptyInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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
} // namespace EmptyInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
