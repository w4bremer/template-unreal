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
#include "Testbed2NestedStruct1InterfaceImplBPFixture.h"
#include "Testbed2NestedStruct1InterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::SetSpec(UTestbed2NestedStruct1InterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

FTestbed2NestedStruct1InterfaceImplBPFixture::FTestbed2NestedStruct1InterfaceImplBPFixture()
{
	testImplementation = NewObject<UTestbed2NestedStruct1InterfaceBPBase>();
	Helper = NewObject<UTestbed2NestedStruct1InterfaceBPBaseImplHelper>();
}

FTestbed2NestedStruct1InterfaceImplBPFixture::~FTestbed2NestedStruct1InterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2NestedStruct1InterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed2NestedStruct1InterfaceBPBaseImplHelper> FTestbed2NestedStruct1InterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTestbed2NestedStruct1InterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::SetSpec(UTestbed2NestedStruct1InterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct1InterfaceBPBaseImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}
#endif // WITH_DEV_AUTOMATION_TESTS
