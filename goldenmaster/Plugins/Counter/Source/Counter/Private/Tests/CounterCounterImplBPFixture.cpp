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
#include "CounterCounterImplBPFixture.h"
#include "CounterCounterImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UCounterCounterBPBaseImplHelper::SetSpec(UCounterCounterBPBaseImplSpec* InSpec)
{
	Spec = InSpec;
}

void UCounterCounterBPBaseImplHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	Spec->VectorPropertyCb(Vector);
}

void UCounterCounterBPBaseImplHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	Spec->VectorArrayPropertyCb(VectorArray);
}

void UCounterCounterBPBaseImplHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	Spec->ValueChangedSignalCb(Vector, ExternVector, VectorArray, ExternVectorArray);
}

FCounterCounterImplBPFixture::FCounterCounterImplBPFixture()
{
	testImplementation = NewObject<UCounterCounterBPBase>();
	Helper = NewObject<UCounterCounterBPBaseImplHelper>();
}

FCounterCounterImplBPFixture::~FCounterCounterImplBPFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UCounterCounterBPBaseImplHelper> FCounterCounterImplBPFixture::GetHelper()
{
	return Helper;
}

void FCounterCounterImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UCounterCounterBPBaseImplHelper::SetSpec(UCounterCounterBPBaseImplSpec* /* InSpec */)
{
}

void UCounterCounterBPBaseImplHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	(void)Vector;
}

void UCounterCounterBPBaseImplHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	(void)VectorArray;
}

void UCounterCounterBPBaseImplHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	(void)Vector;
	(void)ExternVector;
	(void)VectorArray;
	(void)ExternVectorArray;
}
#endif // WITH_DEV_AUTOMATION_TESTS
