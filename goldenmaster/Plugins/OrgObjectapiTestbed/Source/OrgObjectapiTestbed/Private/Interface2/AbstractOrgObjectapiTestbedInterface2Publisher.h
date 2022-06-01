
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

class ORG_OBJECTAPI_TESTBED_API AbstractOrgObjectapiTestbedInterface2Publisher : public IOrgObjectapiTestbedInterface2PublisherInterface
{
public:

    explicit AbstractOrgObjectapiTestbedInterface2Publisher();
    virtual ~AbstractOrgObjectapiTestbedInterface2Publisher();

    // properties
    virtual void SubscribeToOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber) override;
    virtual void UnsubscribeFromOrgObjectapiTestbedInterface2StateChanged(IOrgObjectapiTestbedInterface2SubscriberInterface& Subscriber) override;
    void PublishProp200Changed(int32 Prop200);
    void PublishProp201Changed(int32 Prop201);
    void PublishProp202Changed(int32 Prop202);
    void PublishProp203Changed(float Prop203);
    void PublishProp204Changed(float Prop204);
    void PublishProp205Changed(FString Prop205);

    // signals
private:
    std::set<IOrgObjectapiTestbedInterface2SubscriberInterface*> OrgObjectapiTestbedInterface2StateSubscribers;
};
