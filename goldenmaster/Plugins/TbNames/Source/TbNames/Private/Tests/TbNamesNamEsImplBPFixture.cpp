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
#include "TbNamesNamEsImplBPFixture.h"
#include "TbNamesNamEsImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbNamesNamEsBPBaseImplHelper::SetSpec(UTbNamesNamEsBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsBPBaseImplHelper::SwitchPropertyCb(bool bSwitch)
{
	Spec->SwitchPropertyCb(bSwitch);
}

void UTbNamesNamEsBPBaseImplHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	Spec->SomePropertyPropertyCb(SomeProperty);
}

void UTbNamesNamEsBPBaseImplHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	Spec->SomePoperty2PropertyCb(SomePoperty2);
}

void UTbNamesNamEsBPBaseImplHelper::SomeSignalSignalCb(bool bSomeParam)
{
	Spec->SomeSignalSignalCb(bSomeParam);
}

void UTbNamesNamEsBPBaseImplHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	Spec->SomeSignal2SignalCb(bSomeParam);
}

FTbNamesNamEsImplBPFixture::FTbNamesNamEsImplBPFixture()
{
	testImplementation = NewObject<UTbNamesNamEsBPBase>();
	Helper = NewObject<UTbNamesNamEsBPBaseImplHelper>();
}

FTbNamesNamEsImplBPFixture::~FTbNamesNamEsImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbNamesNamEsBPBaseImplHelper> FTbNamesNamEsImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbNamesNamEsImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbNamesNamEsBPBaseImplHelper::SetSpec(UTbNamesNamEsBPBaseImplSpec* /* InSpec */)
{
}

void UTbNamesNamEsBPBaseImplHelper::SwitchPropertyCb(bool bSwitch)
{
	(void)bSwitch;
}

void UTbNamesNamEsBPBaseImplHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	(void)SomeProperty;
}

void UTbNamesNamEsBPBaseImplHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	(void)SomePoperty2;
}

void UTbNamesNamEsBPBaseImplHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsBPBaseImplHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}
#endif // WITH_DEV_AUTOMATION_TESTS
