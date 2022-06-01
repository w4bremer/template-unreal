
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

#include "AbstractOrgObjectapiTestbedInterface2Publisher.h"
AbstractOrgObjectapiTestbedInterface2Publisher::AbstractOrgObjectapiTestbedInterface2Publisher()
    : IOrgObjectapiTestbedInterface2PublisherInterface()
{
}

AbstractOrgObjectapiTestbedInterface2Publisher::~AbstractOrgObjectapiTestbedInterface2Publisher()
{
}

void AbstractOrgObjectapiTestbedInterface2Publisher::SubscribeToOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber)
{
    OrgObjectapiTestbedInterface2StateSubscribers.insert(&Subscriber);
}

void AbstractOrgObjectapiTestbedInterface2Publisher::UnsubscribeFromOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber)
{
    OrgObjectapiTestbedInterface2StateSubscribers.erase(&Subscriber);
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp200Changed(int32 Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp200Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp201Changed(int32 Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp201Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp202Changed(int32 Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp202Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp203Changed(float Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp203Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp204Changed(float Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp204Changed(Value);
        }
    }
}
void AbstractOrgObjectapiTestbedInterface2Publisher::PublishProp205Changed(FString Value)
{
    for(auto& Subscriber: OrgObjectapiTestbedInterface2StateSubscribers)
    {
        if(Subscriber)
        {
            Subscriber->OnProp205Changed(Value);
        }
    }
}