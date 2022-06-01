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
#pragma once

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"

#include "OrgObjectapiTestbed_data.h"
#include "OrgObjectapiTestbed_apig.generated.h"

/**
 * Interface UOrgObjectapiTestbedInterface1Interface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UOrgObjectapiTestbedInterface1Interface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface IOrgObjectapiTestbedInterface1Interface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface1Interface
{
    GENERATED_BODY()

public:
// methods
    virtual void Op1() = 0;
    virtual void Op2(int32 Step) = 0;
    virtual int32 Op3() = 0;
// properties
    virtual bool GetProp1() const = 0;
    virtual void SetProp1(bool Value) = 0;
    virtual int32 GetProp2() const = 0;
    virtual void SetProp2(int32 Value) = 0;
    virtual float GetProp3() const = 0;
    virtual void SetProp3(float Value) = 0;
    virtual FString GetProp4() const = 0;
    virtual void SetProp4(FString Value) = 0;
    virtual TArray<int32> GetProp5() const = 0;
    virtual void SetProp5(TArray<int32> Value) = 0;
    virtual FStruct1 GetProp6() const = 0;
    virtual void SetProp6(const FStruct1& Value) = 0;
    virtual int32 GetProp7() const = 0;
    virtual void SetProp7(int32 Value) = 0;
    virtual TArray<int32> GetProp10() const = 0;
    virtual void SetProp10(TArray<int32> Value) = 0;
    virtual TArray<FStruct1> GetProp11() const = 0;
    virtual void SetProp11(const TArray<FStruct1>& Value) = 0;
    virtual TArray<EEnum1> GetProp12() const = 0;
    virtual void SetProp12(const TArray<EEnum1>& Value) = 0;
    virtual TArray<FStruct1> GetProp14() const = 0;
    virtual void SetProp14(const TArray<FStruct1>& Value) = 0;
};
/**
 * Interface IOrgObjectapiTestbedInterface1SubscriberInterface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface1SubscriberInterface
{
public:
    virtual void OnSig1() = 0;
    virtual void OnSig2(int32 Step) = 0;
    virtual void OnSig3() = 0;
    virtual void OnbProp1Changed(bool Value) = 0;
    virtual void OnProp2Changed(int32 Value) = 0;
    virtual void OnProp3Changed(float Value) = 0;
    virtual void OnProp4Changed(FString Value) = 0;
    virtual void OnProp5Changed(TArray<int32> Value) = 0;
    virtual void OnProp6Changed(const FStruct1& Value) = 0;
    virtual void OnProp7Changed(int32 Value) = 0;
    virtual void OnProp10Changed(TArray<int32> Value) = 0;
    virtual void OnProp11Changed(const TArray<FStruct1>& Value) = 0;
    virtual void OnProp12Changed(const TArray<EEnum1>& Value) = 0;
    virtual void OnProp14Changed(const TArray<FStruct1>& Value) = 0;
};
/**
 * Interface IOrgObjectapiTestbedInterface1PublisherInterface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface1PublisherInterface: public IOrgObjectapiTestbedInterface1Interface
{
public:
    virtual void SubscribeToOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void UnsubscribeFromOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void SubscribeToSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void UnsubscribeFromSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void SubscribeToSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void UnsubscribeFromSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void SubscribeToSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
    virtual void UnsubscribeFromSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) = 0;
};

/**
 * Interface UOrgObjectapiTestbedInterface2Interface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UOrgObjectapiTestbedInterface2Interface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface IOrgObjectapiTestbedInterface2Interface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface2Interface
{
    GENERATED_BODY()

public:
// methods
// properties
    virtual int32 GetProp200() const = 0;
    virtual void SetProp200(int32 Value) = 0;
    virtual int32 GetProp201() const = 0;
    virtual void SetProp201(int32 Value) = 0;
    virtual int32 GetProp202() const = 0;
    virtual void SetProp202(int32 Value) = 0;
    virtual float GetProp203() const = 0;
    virtual void SetProp203(float Value) = 0;
    virtual float GetProp204() const = 0;
    virtual void SetProp204(float Value) = 0;
    virtual FString GetProp205() const = 0;
    virtual void SetProp205(FString Value) = 0;
};
/**
 * Interface IOrgObjectapiTestbedInterface2SubscriberInterface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface2SubscriberInterface
{
public:
    virtual void OnProp200Changed(int32 Value) = 0;
    virtual void OnProp201Changed(int32 Value) = 0;
    virtual void OnProp202Changed(int32 Value) = 0;
    virtual void OnProp203Changed(float Value) = 0;
    virtual void OnProp204Changed(float Value) = 0;
    virtual void OnProp205Changed(FString Value) = 0;
};
/**
 * Interface IOrgObjectapiTestbedInterface2PublisherInterface
 */
class ORG_OBJECTAPI_TESTBED_API IOrgObjectapiTestbedInterface2PublisherInterface: public IOrgObjectapiTestbedInterface2Interface
{
public:
    virtual void SubscribeToOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber) = 0;
    virtual void UnsubscribeFromOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber) = 0;
};
