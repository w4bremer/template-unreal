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
#include "TbSimpleVoidInterfaceImplBPFixture.h"
#include "TbSimpleVoidInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleVoidInterfaceBPBaseImplHelper::SetSpec(UTbSimpleVoidInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleVoidInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

FTbSimpleVoidInterfaceImplBPFixture::FTbSimpleVoidInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleVoidInterfaceBPBase>();
	Helper = NewObject<UTbSimpleVoidInterfaceBPBaseImplHelper>();
}

FTbSimpleVoidInterfaceImplBPFixture::~FTbSimpleVoidInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleVoidInterfaceBPBaseImplHelper> FTbSimpleVoidInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleVoidInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleVoidInterfaceBPBaseImplHelper::SetSpec(UTbSimpleVoidInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSimpleVoidInterfaceBPBaseImplHelper::SigVoidSignalCb()
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
