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
#include "CounterCounterMsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "Counter/Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Counter/Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace MsgBus
{
namespace Tests
{
FCounterCounterMsgBusFixture::FCounterCounterMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterMsgBusClient>();
}

FCounterCounterMsgBusFixture::~FCounterCounterMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UCounterCounterMsgBusAdapter* FCounterCounterMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterMsgBusAdapter>();
}

UGameInstance* FCounterCounterMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FCounterCounterMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace Counter
} // namespace Counter
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
