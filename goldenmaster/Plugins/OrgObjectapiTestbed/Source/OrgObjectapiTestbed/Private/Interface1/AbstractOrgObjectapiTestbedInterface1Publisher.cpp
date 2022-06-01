
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

#include "AbstractOrgObjectapiTestbedInterface1Publisher.h"
AbstractOrgObjectapiTestbedInterface1Publisher::AbstractOrgObjectapiTestbedInterface1Publisher()
    : IOrgObjectapiTestbedInterface1PublisherInterface()
{
}

AbstractOrgObjectapiTestbedInterface1Publisher::~AbstractOrgObjectapiTestbedInterface1Publisher()
{
}

void AbstractOrgObjectapiTestbedInterface1Publisher::SubscribeToOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    OrgObjectapiTestbedInterface1StateSubscribers.insert(&Subscriber);
}

void AbstractOrgObjectapiTestbedInterface1Publisher::UnsubscribeFromOrgObjectapiTestbedInterface1StateChanged(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    OrgObjectapiTestbedInterface1StateSubscribers.erase(&Subscriber);
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishbProp1Changed(bool Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnbProp1Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp2Changed(int32 Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp2Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp3Changed(float Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp3Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp4Changed(FString Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp4Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp5Changed(const TArray<int32>& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp5Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp6Changed(const FStruct1& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp6Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp7Changed(int32 Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp7Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp10Changed(const TArray<int32>& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp10Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp11Changed(const TArray<FStruct1>& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp11Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp12Changed(const TArray<EEnum1>& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp12Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::PublishProp14Changed(const TArray<FStruct1>& Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface1StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp14Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface1Publisher::SubscribeToSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig1Subscribers.insert(&Subscriber);
}
void AbstractOrgObjectapiTestbedInterface1Publisher::UnsubscribeFromSig1(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig1Subscribers.erase(&Subscriber);
}

void AbstractOrgObjectapiTestbedInterface1Publisher::PublishSig1()
{
    for(auto& Subscriber: Sig1Subscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnSig1();
        }
    }
}

void AbstractOrgObjectapiTestbedInterface1Publisher::SubscribeToSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig2Subscribers.insert(&Subscriber);
}
void AbstractOrgObjectapiTestbedInterface1Publisher::UnsubscribeFromSig2(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig2Subscribers.erase(&Subscriber);
}

void AbstractOrgObjectapiTestbedInterface1Publisher::PublishSig2(int32 Step)
{
    for(auto& Subscriber: Sig2Subscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnSig2(Step);
        }
    }
}

void AbstractOrgObjectapiTestbedInterface1Publisher::SubscribeToSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig3Subscribers.insert(&Subscriber);
}
void AbstractOrgObjectapiTestbedInterface1Publisher::UnsubscribeFromSig3(IOrgObjectapiTestbedInterface1SubscriberInterface& Subscriber)
{
    Sig3Subscribers.erase(&Subscriber);
}

void AbstractOrgObjectapiTestbedInterface1Publisher::PublishSig3()
{
    for(auto& Subscriber: Sig3Subscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnSig3();
        }
    }
}
