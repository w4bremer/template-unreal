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
#include "TbSimpleEmptyInterfaceImplBPFixture.h"
#include "TbSimpleEmptyInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleEmptyInterfaceBPBaseImplHelper::SetSpec(UTbSimpleEmptyInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

FTbSimpleEmptyInterfaceImplBPFixture::FTbSimpleEmptyInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleEmptyInterfaceBPBase>();
	Helper = NewObject<UTbSimpleEmptyInterfaceBPBaseImplHelper>();
}

FTbSimpleEmptyInterfaceImplBPFixture::~FTbSimpleEmptyInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleEmptyInterfaceBPBaseImplHelper> FTbSimpleEmptyInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleEmptyInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleEmptyInterfaceBPBaseImplHelper::SetSpec(UTbSimpleEmptyInterfaceBPBaseImplSpec* /* InSpec */)
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
