
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

#include "apig/TbSame2_apig.h"

namespace TbSame2 {
namespace SameStruct2Interface {
namespace Private {

class LocalService : public ITbSame2SameStruct2InterfaceInterface
{
public:

    explicit LocalService();
    virtual ~LocalService();

    // signals
    FTbSame2SameStruct2InterfaceSig1Delegate Sig1Signal;
    FTbSame2SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
    FTbSame2SameStruct2InterfaceSig2Delegate Sig2Signal;
    FTbSame2SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;
    
    FTbSame2SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
    FTbSame2SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

    FTbSame2SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
    FTbSame2SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;


    // properties
    FTbSame2Struct2 GetProp1() const override;
    void SetProp1(const FTbSame2Struct2& Prop1) override;

    FTbSame2Struct2 GetProp2() const override;
    void SetProp2(const FTbSame2Struct2& Prop2) override;


    // operations
    FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;
    
    FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
    

private:
    // properties - local copy - use setter functions to emit changed signals
    FTbSame2Struct2 Prop1;
    FTbSame2Struct2 Prop2;
};

} // namespace Private
} // namespace SameStruct2Interface
} // namespace TbSame2