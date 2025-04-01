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
#include "TbSame1SameStruct1InterfaceImplBPFixture.h"
#include "TbSame1SameStruct1InterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameStruct1InterfaceBPBaseImplHelper::SetSpec(UTbSame1SameStruct1InterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct1InterfaceBPBaseImplHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame1SameStruct1InterfaceBPBaseImplHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

FTbSame1SameStruct1InterfaceImplBPFixture::FTbSame1SameStruct1InterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSame1SameStruct1InterfaceBPBase>();
	Helper = NewObject<UTbSame1SameStruct1InterfaceBPBaseImplHelper>();
}

FTbSame1SameStruct1InterfaceImplBPFixture::~FTbSame1SameStruct1InterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSame1SameStruct1InterfaceBPBaseImplHelper> FTbSame1SameStruct1InterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSame1SameStruct1InterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameStruct1InterfaceBPBaseImplHelper::SetSpec(UTbSame1SameStruct1InterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSame1SameStruct1InterfaceBPBaseImplHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct1InterfaceBPBaseImplHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}
#endif // WITH_DEV_AUTOMATION_TESTS
