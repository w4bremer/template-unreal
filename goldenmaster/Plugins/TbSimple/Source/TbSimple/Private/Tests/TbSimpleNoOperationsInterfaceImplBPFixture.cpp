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
#include "TbSimpleNoOperationsInterfaceImplBPFixture.h"
#include "TbSimpleNoOperationsInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoOperationsInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

FTbSimpleNoOperationsInterfaceImplBPFixture::FTbSimpleNoOperationsInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleNoOperationsInterfaceBPBase>();
	Helper = NewObject<UTbSimpleNoOperationsInterfaceBPBaseImplHelper>();
}

FTbSimpleNoOperationsInterfaceImplBPFixture::~FTbSimpleNoOperationsInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoOperationsInterfaceBPBaseImplHelper> FTbSimpleNoOperationsInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleNoOperationsInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoOperationsInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceBPBaseImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
