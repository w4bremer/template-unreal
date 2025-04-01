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
#include "Testbed1StructInterfaceImplBPFixture.h"
#include "Testbed1StructInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructInterfaceBPBaseImplHelper::SetSpec(UTestbed1StructInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

FTestbed1StructInterfaceImplBPFixture::FTestbed1StructInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTestbed1StructInterfaceBPBase>();
	Helper = NewObject<UTestbed1StructInterfaceBPBaseImplHelper>();
}

FTestbed1StructInterfaceImplBPFixture::~FTestbed1StructInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed1StructInterfaceBPBaseImplHelper> FTestbed1StructInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTestbed1StructInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructInterfaceBPBaseImplHelper::SetSpec(UTestbed1StructInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructInterfaceBPBaseImplHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	(void)PropString;
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructInterfaceBPBaseImplHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
