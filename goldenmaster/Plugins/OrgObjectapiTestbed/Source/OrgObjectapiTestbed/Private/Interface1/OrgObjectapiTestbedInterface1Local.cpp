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

#include "OrgObjectapiTestbedInterface1Local.h"
OrgObjectapiTestbedInterface1LocalService::OrgObjectapiTestbedInterface1LocalService()
    : AbstractOrgObjectapiTestbedInterface1Publisher()
    , bProp1(false)
    , Prop2(0)
    , Prop3(0.0f)
    , Prop4(FString())
    , Prop5(TArray<int32>())
    , Prop6(FStruct1())
    , Prop7(0)
    , Prop10(TArray<int32>())
    , Prop11(TArray<FStruct1>())
    , Prop12(TArray<EEnum1>())
    , Prop14(TArray<FStruct1>())
{
}
OrgObjectapiTestbedInterface1LocalService::~OrgObjectapiTestbedInterface1LocalService()
{
}

bool OrgObjectapiTestbedInterface1LocalService::GetProp1() const
{
    return bProp1;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp1(bool Value)
{
    if(bProp1 != Value)
    {
        bProp1 = Value;
        PublishbProp1Changed(bProp1);
    }
}
int32 OrgObjectapiTestbedInterface1LocalService::GetProp2() const
{
    return Prop2;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp2(int32 Value)
{
    if(Prop2 != Value)
    {
        Prop2 = Value;
        PublishProp2Changed(Prop2);
    }
}
float OrgObjectapiTestbedInterface1LocalService::GetProp3() const
{
    return Prop3;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp3(float Value)
{
    if(Prop3 != Value)
    {
        Prop3 = Value;
        PublishProp3Changed(Prop3);
    }
}
FString OrgObjectapiTestbedInterface1LocalService::GetProp4() const
{
    return Prop4;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp4(FString Value)
{
    if(Prop4 != Value)
    {
        Prop4 = Value;
        PublishProp4Changed(Prop4);
    }
}
TArray<int32> OrgObjectapiTestbedInterface1LocalService::GetProp5() const
{
    return Prop5;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp5(TArray<int32> Value)
{
    if(Prop5 != Value)
    {
        Prop5 = Value;
        PublishProp5Changed(Prop5);
    }
}
FStruct1 OrgObjectapiTestbedInterface1LocalService::GetProp6() const
{
    return Prop6;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp6(const FStruct1& Value)
{
    if(Prop6 != Value)
    {
        Prop6 = Value;
        PublishProp6Changed(Prop6);
    }
}
int32 OrgObjectapiTestbedInterface1LocalService::GetProp7() const
{
    return Prop7;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp7(int32 Value)
{
    if(Prop7 != Value)
    {
        Prop7 = Value;
        PublishProp7Changed(Prop7);
    }
}
TArray<int32> OrgObjectapiTestbedInterface1LocalService::GetProp10() const
{
    return Prop10;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp10(TArray<int32> Value)
{
    if(Prop10 != Value)
    {
        Prop10 = Value;
        PublishProp10Changed(Prop10);
    }
}
TArray<FStruct1> OrgObjectapiTestbedInterface1LocalService::GetProp11() const
{
    return Prop11;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp11(const TArray<FStruct1>& Value)
{
    if(Prop11 != Value)
    {
        Prop11 = Value;
        PublishProp11Changed(Prop11);
    }
}
TArray<EEnum1> OrgObjectapiTestbedInterface1LocalService::GetProp12() const
{
    return Prop12;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp12(const TArray<EEnum1>& Value)
{
    if(Prop12 != Value)
    {
        Prop12 = Value;
        PublishProp12Changed(Prop12);
    }
}
TArray<FStruct1> OrgObjectapiTestbedInterface1LocalService::GetProp14() const
{
    return Prop14;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp14(const TArray<FStruct1>& Value)
{
    if(Prop14 != Value)
    {
        Prop14 = Value;
        PublishProp14Changed(Prop14);
    }
}

void OrgObjectapiTestbedInterface1LocalService::Op1()
{
    // do business logic here
}
void OrgObjectapiTestbedInterface1LocalService::Op2(int32 Step)
{
    (void) Step;
    // do business logic here
}
int32 OrgObjectapiTestbedInterface1LocalService::Op3()
{
    // do business logic here
    return 0;
}
