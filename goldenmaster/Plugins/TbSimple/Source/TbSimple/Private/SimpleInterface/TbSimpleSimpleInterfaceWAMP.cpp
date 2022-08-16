
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

#include "TbSimpleSimpleInterfaceWAMP.h"
#include "apig/TbSimple.json.adapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "unrealwamp.h"

using namespace ApiGear::WAMP;

namespace TbSimple {
namespace SimpleInterface {
namespace Private {
WAMPService::WAMPService()
: ITbSimpleSimpleInterfaceInterface()
, bPropBool(false)
, PropInt(0)
, PropFloat(0.0f)
, PropString(FString())
{
    EventFunc SimpleInterfaceStateChangedFunc = [this](EventArg arg)
    {
        const json fields = arg.kwargs;
        if(fields.contains("propBool")) {
            if(bPropBool != fields["propBool"].get<bool>())
            {
                bPropBool = fields["propBool"].get<bool>();
                PropBoolChanged.Broadcast(bPropBool);
            }
        }
        if(fields.contains("propInt")) {
            if(PropInt != fields["propInt"].get<int32>())
            {
                PropInt = fields["propInt"].get<int32>();
                PropIntChanged.Broadcast(PropInt);
            }
        }
        if(fields.contains("propFloat")) {
            if(PropFloat != fields["propFloat"].get<float>())
            {
                PropFloat = fields["propFloat"].get<float>();
                PropFloatChanged.Broadcast(PropFloat);
            }
        }
        if(fields.contains("propString")) {
            if(PropString != fields["propString"].get<FString>())
            {
                PropString = fields["propString"].get<FString>();
                PropStringChanged.Broadcast(PropString);
            }
        }
    };
    UnrealWamp::instance()->doSubscribe("tb.simple.SimpleInterface", SimpleInterfaceStateChangedFunc);

    ResponseFunc GetSimpleInterfaceStateFunc = [this](ResponseArg arg)
    {
        if(arg.args.size() != 1) {
          return;
        }
        const json fields = arg.args[0];
        if(fields.contains("propBool")) {
            if(bPropBool != fields["propBool"].get<bool>())
            {
                bPropBool = fields["propBool"].get<bool>();
                PropBoolChanged.Broadcast(bPropBool);
            }
        }
        if(fields.contains("propInt")) {
            if(PropInt != fields["propInt"].get<int32>())
            {
                PropInt = fields["propInt"].get<int32>();
                PropIntChanged.Broadcast(PropInt);
            }
        }
        if(fields.contains("propFloat")) {
            if(PropFloat != fields["propFloat"].get<float>())
            {
                PropFloat = fields["propFloat"].get<float>();
                PropFloatChanged.Broadcast(PropFloat);
            }
        }
        if(fields.contains("propString")) {
            if(PropString != fields["propString"].get<FString>())
            {
                PropString = fields["propString"].get<FString>();
                PropStringChanged.Broadcast(PropString);
            }
        }
    };
    UnrealWamp::instance()->doCall("tb.simple.SimpleInterface._get", Arguments(), ArgumentsKw(), GetSimpleInterfaceStateFunc);

    EventFunc sigBoolFunc = [this](EventArg arg)
    {
        if(arg.args.size() == 1)
        {
            SigBoolSignal.Broadcast(arg.args[0].get<bool>());
        }
    };
    UnrealWamp::instance()->doSubscribe("tb.simple.SimpleInterface.sigBool", sigBoolFunc);
    
    EventFunc sigIntFunc = [this](EventArg arg)
    {
        if(arg.args.size() == 1)
        {
            SigIntSignal.Broadcast(arg.args[0].get<int32>());
        }
    };
    UnrealWamp::instance()->doSubscribe("tb.simple.SimpleInterface.sigInt", sigIntFunc);
    
    EventFunc sigFloatFunc = [this](EventArg arg)
    {
        if(arg.args.size() == 1)
        {
            SigFloatSignal.Broadcast(arg.args[0].get<float>());
        }
    };
    UnrealWamp::instance()->doSubscribe("tb.simple.SimpleInterface.sigFloat", sigFloatFunc);
    
    EventFunc sigStringFunc = [this](EventArg arg)
    {
        if(arg.args.size() == 1)
        {
            SigStringSignal.Broadcast(arg.args[0].get<FString>());
        }
    };
    UnrealWamp::instance()->doSubscribe("tb.simple.SimpleInterface.sigString", sigStringFunc);
    
}

WAMPService::~WAMPService()
{
    UnrealWamp::instance()->doUnSubscribe("tb.simple.SimpleInterface");
    UnrealWamp::instance()->doUnSubscribe("tb.simple.SimpleInterface.sigBool");
    UnrealWamp::instance()->doUnSubscribe("tb.simple.SimpleInterface.sigInt");
    UnrealWamp::instance()->doUnSubscribe("tb.simple.SimpleInterface.sigFloat");
    UnrealWamp::instance()->doUnSubscribe("tb.simple.SimpleInterface.sigString");
}

FTbSimpleSimpleInterfaceSigBoolDelegate& WAMPService::GetSigBoolSignalDelegate()
{
    return SigBoolSignal;
}

FTbSimpleSimpleInterfaceSigIntDelegate& WAMPService::GetSigIntSignalDelegate()
{
    return SigIntSignal;
}

FTbSimpleSimpleInterfaceSigFloatDelegate& WAMPService::GetSigFloatSignalDelegate()
{
    return SigFloatSignal;
}

FTbSimpleSimpleInterfaceSigStringDelegate& WAMPService::GetSigStringSignalDelegate()
{
    return SigStringSignal;
}

bool WAMPService::GetPropBool() const
{
    return bPropBool;
}

void WAMPService::SetPropBool(bool bInPropBool)
{
    ArgumentsKw fields_;
    fields_["propBool"] = bInPropBool;
    UnrealWamp::instance()->doCall("tb.simple.SimpleInterface._set", Arguments(), fields_);
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& WAMPService::GetPropBoolChangedDelegate()
{
    return PropBoolChanged;
}

int32 WAMPService::GetPropInt() const
{
    return PropInt;
}

void WAMPService::SetPropInt(int32 InPropInt)
{
    ArgumentsKw fields_;
    fields_["propInt"] = InPropInt;
    UnrealWamp::instance()->doCall("tb.simple.SimpleInterface._set", Arguments(), fields_);
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& WAMPService::GetPropIntChangedDelegate()
{
    return PropIntChanged;
}

float WAMPService::GetPropFloat() const
{
    return PropFloat;
}

void WAMPService::SetPropFloat(float InPropFloat)
{
    ArgumentsKw fields_;
    fields_["propFloat"] = InPropFloat;
    UnrealWamp::instance()->doCall("tb.simple.SimpleInterface._set", Arguments(), fields_);
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& WAMPService::GetPropFloatChangedDelegate()
{
    return PropFloatChanged;
}

FString WAMPService::GetPropString() const
{
    return PropString;
}

void WAMPService::SetPropString(const FString& InPropString)
{
    ArgumentsKw fields_;
    fields_["propString"] = InPropString;
    UnrealWamp::instance()->doCall("tb.simple.SimpleInterface._set", Arguments(), fields_);
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& WAMPService::GetPropStringChangedDelegate()
{
    return PropStringChanged;
}


bool WAMPService::FuncBool(bool bParamBool)
{
    TPromise<bool> Promise;
    Async(EAsyncExecution::Thread, [bParamBool,&Promise]()
    {
        ResponseFunc GetSimpleInterfaceStateFunc = [&Promise](ResponseArg arg)
        {
            if(arg.args.size() != 1) {
              return;
            }
            Promise.SetValue(arg.args[0].get<bool>());
        };
        UnrealWamp::instance()->doCall("tb.simple.SimpleInterface.funcBool", {bParamBool}, ArgumentsKw(), GetSimpleInterfaceStateFunc);
    });

    return Promise.GetFuture().Get();
}

int32 WAMPService::FuncInt(int32 ParamInt)
{
    TPromise<int32> Promise;
    Async(EAsyncExecution::Thread, [ParamInt,&Promise]()
    {
        ResponseFunc GetSimpleInterfaceStateFunc = [&Promise](ResponseArg arg)
        {
            if(arg.args.size() != 1) {
              return;
            }
            Promise.SetValue(arg.args[0].get<int32>());
        };
        UnrealWamp::instance()->doCall("tb.simple.SimpleInterface.funcInt", {ParamInt}, ArgumentsKw(), GetSimpleInterfaceStateFunc);
    });

    return Promise.GetFuture().Get();
}

float WAMPService::FuncFloat(float ParamFloat)
{
    TPromise<float> Promise;
    Async(EAsyncExecution::Thread, [ParamFloat,&Promise]()
    {
        ResponseFunc GetSimpleInterfaceStateFunc = [&Promise](ResponseArg arg)
        {
            if(arg.args.size() != 1) {
              return;
            }
            Promise.SetValue(arg.args[0].get<float>());
        };
        UnrealWamp::instance()->doCall("tb.simple.SimpleInterface.funcFloat", {ParamFloat}, ArgumentsKw(), GetSimpleInterfaceStateFunc);
    });

    return Promise.GetFuture().Get();
}

FString WAMPService::FuncString(const FString& ParamString)
{
    TPromise<FString> Promise;
    Async(EAsyncExecution::Thread, [ParamString,&Promise]()
    {
        ResponseFunc GetSimpleInterfaceStateFunc = [&Promise](ResponseArg arg)
        {
            if(arg.args.size() != 1) {
              return;
            }
            Promise.SetValue(arg.args[0].get<FString>());
        };
        UnrealWamp::instance()->doCall("tb.simple.SimpleInterface.funcString", {ParamString}, ArgumentsKw(), GetSimpleInterfaceStateFunc);
    });

    return Promise.GetFuture().Get();
}


} // namespace Private
} // namespace SimpleInterface
} // namespace TbSimple