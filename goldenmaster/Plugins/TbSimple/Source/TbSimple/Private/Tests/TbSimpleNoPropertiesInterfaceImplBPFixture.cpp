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
#include "TbSimpleNoPropertiesInterfaceImplBPFixture.h"
#include "TbSimpleNoPropertiesInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoPropertiesInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

FTbSimpleNoPropertiesInterfaceImplBPFixture::FTbSimpleNoPropertiesInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleNoPropertiesInterfaceBPBase>();
	Helper = NewObject<UTbSimpleNoPropertiesInterfaceBPBaseImplHelper>();
}

FTbSimpleNoPropertiesInterfaceImplBPFixture::~FTbSimpleNoPropertiesInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoPropertiesInterfaceBPBaseImplHelper> FTbSimpleNoPropertiesInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleNoPropertiesInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SetSpec(UTbSimpleNoPropertiesInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoPropertiesInterfaceBPBaseImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
