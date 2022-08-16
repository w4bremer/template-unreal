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

#include "apig/TbSame1_apig.h"

namespace TbSame1 {
namespace SameStruct1Interface {
namespace Private {
    
class SimulationService : public ITbSame1SameStruct1InterfaceInterface
{
public:

    explicit SimulationService();
    virtual ~SimulationService();

    // signals
    FTbSame1SameStruct1InterfaceSig1Delegate Sig1Signal;
    FTbSame1SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
    FTbSame1SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
    FTbSame1SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;


    // properties
    FTbSame1Struct1 GetProp1() const override;
    void SetProp1(const FTbSame1Struct1& Prop1) override;


    // operations
    FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;
    

private:
    // properties - local copy
    FTbSame1Struct1 Prop1;
};

} // namespace Private
} // namespace SameStruct1Interface
} // namespace TbSame1