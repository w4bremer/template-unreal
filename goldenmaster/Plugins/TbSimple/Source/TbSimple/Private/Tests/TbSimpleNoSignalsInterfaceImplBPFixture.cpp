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
#include "TbSimpleNoSignalsInterfaceImplBPFixture.h"
#include "TbSimpleNoSignalsInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoSignalsInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

FTbSimpleNoSignalsInterfaceImplBPFixture::FTbSimpleNoSignalsInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleNoSignalsInterfaceBPBase>();
	Helper = NewObject<UTbSimpleNoSignalsInterfaceBPBaseImplHelper>();
}

FTbSimpleNoSignalsInterfaceImplBPFixture::~FTbSimpleNoSignalsInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoSignalsInterfaceBPBaseImplHelper> FTbSimpleNoSignalsInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleNoSignalsInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoSignalsInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoSignalsInterfaceBPBaseImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}
#endif // WITH_DEV_AUTOMATION_TESTS
