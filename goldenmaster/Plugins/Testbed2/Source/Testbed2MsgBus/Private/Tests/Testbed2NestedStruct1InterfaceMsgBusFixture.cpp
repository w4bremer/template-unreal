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
#include "Testbed2NestedStruct1InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusClient.h"
#include "Testbed2/Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace MsgBus
{
namespace Tests
{
FTestbed2NestedStruct1InterfaceMsgBusFixture::FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusClient>();
}

FTestbed2NestedStruct1InterfaceMsgBusFixture::~FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1Interface> FTestbed2NestedStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct1InterfaceMsgBusAdapter* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NestedStruct1Interface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
