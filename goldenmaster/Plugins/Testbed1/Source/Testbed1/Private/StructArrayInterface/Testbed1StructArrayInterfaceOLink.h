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

#include "apig/Testbed1_apig.h"
#include "olink/clientnode.h"

namespace Testbed1 {
namespace StructArrayInterface {
namespace Private {

class OLinkService : public ITestbed1StructArrayInterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

    explicit OLinkService();
    virtual ~OLinkService();

    // signals
    FTestbed1StructArrayInterfaceSigBoolDelegate SigBoolSignal;
    FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;
    
    FTestbed1StructArrayInterfaceSigIntDelegate SigIntSignal;
    FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;
    
    FTestbed1StructArrayInterfaceSigFloatDelegate SigFloatSignal;
    FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;
    
    FTestbed1StructArrayInterfaceSigStringDelegate SigStringSignal;
    FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;
    
    FTestbed1StructArrayInterfacePropBoolChangedDelegate PropBoolChanged;
    FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

    FTestbed1StructArrayInterfacePropIntChangedDelegate PropIntChanged;
    FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

    FTestbed1StructArrayInterfacePropFloatChangedDelegate PropFloatChanged;
    FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

    FTestbed1StructArrayInterfacePropStringChangedDelegate PropStringChanged;
    FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

    // properties
    TArray<FTestbed1StructBool> GetPropBool() const override;
    void SetPropBool(const TArray<FTestbed1StructBool>& PropBool) override;

    TArray<FTestbed1StructInt> GetPropInt() const override;
    void SetPropInt(const TArray<FTestbed1StructInt>& PropInt) override;

    TArray<FTestbed1StructFloat> GetPropFloat() const override;
    void SetPropFloat(const TArray<FTestbed1StructFloat>& PropFloat) override;

    TArray<FTestbed1StructString> GetPropString() const override;
    void SetPropString(const TArray<FTestbed1StructString>& PropString) override;


    // operations
    FTestbed1StructBool FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;
    
    FTestbed1StructBool FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;
    
    FTestbed1StructBool FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;
    
    FTestbed1StructBool FuncString(const TArray<FTestbed1StructString>& ParamString) override;
    

    // olink sink interface
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;

private:
    void applyState(const nlohmann::json& fields);
    
    ApiGear::ObjectLink::IClientNode *m_node;
    bool m_isReady;
    // properties - local copy
    TArray<FTestbed1StructBool> PropBool;
    TArray<FTestbed1StructInt> PropInt;
    TArray<FTestbed1StructFloat> PropFloat;
    TArray<FTestbed1StructString> PropString;
};

} // namespace Private
} // namespace StructArrayInterface
} // namespace Testbed1