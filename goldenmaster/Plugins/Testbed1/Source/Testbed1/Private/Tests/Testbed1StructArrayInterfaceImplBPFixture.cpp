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
#include "Testbed1StructArrayInterfaceImplBPFixture.h"
#include "Testbed1StructArrayInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SetSpec(UTestbed1StructArrayInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

FTestbed1StructArrayInterfaceImplBPFixture::FTestbed1StructArrayInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTestbed1StructArrayInterfaceBPBase>();
	Helper = NewObject<UTestbed1StructArrayInterfaceBPBaseImplHelper>();
}

FTestbed1StructArrayInterfaceImplBPFixture::~FTestbed1StructArrayInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed1StructArrayInterfaceBPBaseImplHelper> FTestbed1StructArrayInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTestbed1StructArrayInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArrayInterfaceBPBaseImplHelper::SetSpec(UTestbed1StructArrayInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	(void)PropString;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArrayInterfaceBPBaseImplHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
