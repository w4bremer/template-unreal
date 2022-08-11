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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "TbSame1SameEnum1InterfaceSimulation.h"
#include "apig/TbSame1.json.adapter.h"
#include "unrealsimulation.h"

using namespace ApiGear::JSONRPC;

namespace TbSame1 {
namespace SameEnum1Interface {
namespace Private {
SimulationService::SimulationService()
    : ITbSame1SameEnum1InterfaceInterface()
    , Prop1(ETbSame1Enum1::VALUE1)
{
    UApiGearConnectionManager* AGCM = nullptr;
    if (GEngine != nullptr)
    {
        AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
    }
    NotifyRequestFunc SameEnum1InterfaceStateChangedFunc = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("prop1")) {
            if(Prop1 != fields["prop1"].get<ETbSame1Enum1>())
            {
                Prop1 = fields["prop1"].get<ETbSame1Enum1>();
                Prop1Changed.Broadcast(Prop1);
            }
        }
    };
    if(AGCM != nullptr)
    {   
        AGCM->GetSimulationConnection()->Connect();
        AGCM->GetSimulationConnection()->onNotifyState("tb.same1/SameEnum1Interface", SameEnum1InterfaceStateChangedFunc);
    }

    CallResponseFunc GetSameEnum1InterfaceStateFunc = [this](CallResponseArg arg)
    {
        if(arg.result.size() != 1) {
          return;
        }
        const json fields = arg.result;
        if(fields.contains("prop1")) {
            if(Prop1 != fields["prop1"].get<ETbSame1Enum1>())
            {
                Prop1 = fields["prop1"].get<ETbSame1Enum1>();
                Prop1Changed.Broadcast(Prop1);
            }
        }
    };
    if(AGCM != nullptr)
    {
        AGCM->GetSimulationConnection()->doFetchState("tb.same1/SameEnum1Interface", GetSameEnum1InterfaceStateFunc);
    }

    // register notification callback functions, signal/event -> fcn
    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("param1"))
        {
            Sig1Signal.Broadcast(fields["param1"].get<ETbSame1Enum1>());
        }
    };
    if(AGCM != nullptr)
    {
        AGCM->GetSimulationConnection()->onNotify("tb.same1/SameEnum1Interface#sig1", sig1Func);
    }

}

SimulationService::~SimulationService()
{
    if (GEngine != nullptr)
    {
        UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
        AGCM->GetSimulationConnection()->RemoveOnNotifyState("tb.same1/SameEnum1Interface");
        // unregister notification callback functions
        AGCM->GetSimulationConnection()->RemoveOnNotify("tb.same1/SameEnum1Interface#sig1");
    }
}

FTbSame1SameEnum1InterfaceSig1Delegate& SimulationService::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

ETbSame1Enum1 SimulationService::GetProp1() const
{
    return Prop1;
}

void SimulationService::SetProp1(const ETbSame1Enum1& InProp1)
{
    Params params;
    params["prop1"] = InProp1;
    if (GEngine != nullptr)
    {
        UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
        AGCM->GetSimulationConnection()->doCall("tb.same1/SameEnum1Interface", "_set", params);
    }
}

FTbSame1SameEnum1InterfaceProp1ChangedDelegate& SimulationService::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}

ETbSame1Enum1 SimulationService::Func1(const ETbSame1Enum1& Param1)
{
    Params params;
    params["param1"] = Param1;
    TPromise<ETbSame1Enum1> Promise;
    Async(EAsyncExecution::Thread, [params, &Promise]()
    {
        CallResponseFunc GetSameEnum1InterfaceStateFunc = [&Promise](CallResponseArg arg)
        {
            Promise.SetValue(arg.result.get<ETbSame1Enum1>());
        };
        if (GEngine != nullptr)
        {
            UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
            AGCM->GetSimulationConnection()->doCall("tb.same1/SameEnum1Interface", "func1", params, GetSameEnum1InterfaceStateFunc);
        }
    });

    return Promise.GetFuture().Get();
}


} // namespace Private
} // namespace SameEnum1Interface
} // namespace TbSame1
