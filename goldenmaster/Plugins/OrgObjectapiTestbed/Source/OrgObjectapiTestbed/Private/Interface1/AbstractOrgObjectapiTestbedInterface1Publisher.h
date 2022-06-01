
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

#include "apig/OrgObjectapiTestbed_apig.h"
#include <set>

class ORG_OBJECTAPI_TESTBED_API AbstractOrgObjectapiTestbedInterface1Publisher : public IOrgObjectapiTestbedInterface1PublisherInterface
{
public:

    explicit AbstractOrgObjectapiTestbedInterface1Publisher();
    virtual ~AbstractOrgObjectapiTestbedInterface1Publisher();

    // properties
    virtual void SubscribeToOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    virtual void UnsubscribeFromOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void PublishbProp1Changed(bool bProp1);
    void PublishProp2Changed(int32 Prop2);
    void PublishProp3Changed(float Prop3);
    void PublishProp4Changed(FString Prop4);
    void PublishProp5Changed(const TArray<int32>& Prop5);
    void PublishProp6Changed(const FStruct1& Prop6);
    void PublishProp7Changed(int32 Prop7);
    void PublishProp10Changed(const TArray<int32>& Prop10);
    void PublishProp11Changed(const TArray<FStruct1>& Prop11);
    void PublishProp12Changed(const TArray<EEnum1>& Prop12);
    void PublishProp14Changed(const TArray<FStruct1>& Prop14);

    // signals
    void SubscribeToSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void UnsubscribeFromSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void PublishSig1();
    
    void SubscribeToSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void UnsubscribeFromSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void PublishSig2(int32 Step);
    
    void SubscribeToSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void UnsubscribeFromSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber) override;
    void PublishSig3();
    
private:
    std::set<IOrgObjectapiTestbedInterface1SubscriberInterface*> OrgObjectapiTestbedInterface1StateSubscribers;
    std::set<IOrgObjectapiTestbedInterface1SubscriberInterface*> Sig1Subscribers;
    std::set<IOrgObjectapiTestbedInterface1SubscriberInterface*> Sig2Subscribers;
    std::set<IOrgObjectapiTestbedInterface1SubscriberInterface*> Sig3Subscribers;
};
