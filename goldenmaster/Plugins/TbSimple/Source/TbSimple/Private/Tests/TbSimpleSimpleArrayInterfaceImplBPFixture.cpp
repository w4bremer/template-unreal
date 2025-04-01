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
#include "TbSimpleSimpleArrayInterfaceImplBPFixture.h"
#include "TbSimpleSimpleArrayInterfaceImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SetSpec(UTbSimpleSimpleArrayInterfaceBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	Spec->PropInt32PropertyCb(PropInt32);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	Spec->PropInt64PropertyCb(PropInt64);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	Spec->PropFloat32PropertyCb(PropFloat32);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	Spec->PropFloat64PropertyCb(PropFloat64);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	Spec->SigInt32SignalCb(ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	Spec->SigInt64SignalCb(ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	Spec->SigFloat32SignalCb(ParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	Spec->SigFloat64SignalCb(ParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

FTbSimpleSimpleArrayInterfaceImplBPFixture::FTbSimpleSimpleArrayInterfaceImplBPFixture()
{
	testImplementation = NewObject<UTbSimpleSimpleArrayInterfaceBPBase>();
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceBPBaseImplHelper>();
}

FTbSimpleSimpleArrayInterfaceImplBPFixture::~FTbSimpleSimpleArrayInterfaceImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleSimpleArrayInterfaceBPBaseImplHelper> FTbSimpleSimpleArrayInterfaceImplBPFixture::GetHelper()
{
	return Helper;
}

void FTbSimpleSimpleArrayInterfaceImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SetSpec(UTbSimpleSimpleArrayInterfaceBPBaseImplSpec* /* InSpec */)
{
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	(void)PropBool;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
