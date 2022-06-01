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

#include "OrgObjectapiTestbedInterface2Local.h"
OrgObjectapiTestbedInterface2LocalService::OrgObjectapiTestbedInterface2LocalService()
    : AbstractOrgObjectapiTestbedInterface2Publisher()
    , Prop200(0)
    , Prop201(0)
    , Prop202(0)
    , Prop203(0.0f)
    , Prop204(0.0f)
    , Prop205(FString())
{
}
OrgObjectapiTestbedInterface2LocalService::~OrgObjectapiTestbedInterface2LocalService()
{
}

int32 OrgObjectapiTestbedInterface2LocalService::GetProp200() const
{
    return Prop200;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp200(int32 Value)
{
    if(Prop200 != Value)
    {
        Prop200 = Value;
        PublishProp200Changed(Prop200);
    }
}
int32 OrgObjectapiTestbedInterface2LocalService::GetProp201() const
{
    return Prop201;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp201(int32 Value)
{
    if(Prop201 != Value)
    {
        Prop201 = Value;
        PublishProp201Changed(Prop201);
    }
}
int32 OrgObjectapiTestbedInterface2LocalService::GetProp202() const
{
    return Prop202;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp202(int32 Value)
{
    if(Prop202 != Value)
    {
        Prop202 = Value;
        PublishProp202Changed(Prop202);
    }
}
float OrgObjectapiTestbedInterface2LocalService::GetProp203() const
{
    return Prop203;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp203(float Value)
{
    if(Prop203 != Value)
    {
        Prop203 = Value;
        PublishProp203Changed(Prop203);
    }
}
float OrgObjectapiTestbedInterface2LocalService::GetProp204() const
{
    return Prop204;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp204(float Value)
{
    if(Prop204 != Value)
    {
        Prop204 = Value;
        PublishProp204Changed(Prop204);
    }
}
FString OrgObjectapiTestbedInterface2LocalService::GetProp205() const
{
    return Prop205;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp205(FString Value)
{
    if(Prop205 != Value)
    {
        Prop205 = Value;
        PublishProp205Changed(Prop205);
    }
}

