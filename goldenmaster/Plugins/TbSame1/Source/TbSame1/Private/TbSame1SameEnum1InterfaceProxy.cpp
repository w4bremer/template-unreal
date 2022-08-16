
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
#include "TbSame1SameEnum1InterfaceProxy.h"
#include "SameEnum1Interface/TbSame1SameEnum1InterfaceLocal.h"
#include "apig/TbSame1.trace.h"
#include "TbSame1Factory.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame1SameEnum1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameEnum1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

    void Cancel() {
        bInProgress = false;
    }

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};
UTbSame1SameEnum1InterfaceProxy::UTbSame1SameEnum1InterfaceProxy()
    : ITbSame1SameEnum1InterfaceInterface()
    , Prop1(ETbSame1Enum1::VALUE1)
{
    service = FTbSame1ModuleFactory::createITbSame1SameEnum1InterfaceInterface();
    service->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame1SameEnum1InterfaceProxy::OnProp1Changed);
    service->GetSig1SignalDelegate().AddDynamic(this, &UTbSame1SameEnum1InterfaceProxy::OnSig1);
}

UTbSame1SameEnum1InterfaceProxy::~UTbSame1SameEnum1InterfaceProxy()
{
    service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame1SameEnum1InterfaceProxy::OnProp1Changed);
    service->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame1SameEnum1InterfaceProxy::OnSig1);
}
void UTbSame1SameEnum1InterfaceProxy::OnSig1(const ETbSame1Enum1& Param1)
{
    TbSame1SameEnum1InterfaceTracer::trace_signalSig1(Param1);
    Sig1Signal.Broadcast(Param1);
}

FTbSame1SameEnum1InterfaceSig1Delegate& UTbSame1SameEnum1InterfaceProxy::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

void UTbSame1SameEnum1InterfaceProxy::OnProp1Changed(const ETbSame1Enum1& InProp1)
{
    TbSame1SameEnum1InterfaceTracer::capture_state(this);
    Prop1Changed.Broadcast(InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceProxy::GetProp1() const
{
    return service->GetProp1();
}

void UTbSame1SameEnum1InterfaceProxy::SetProp1(const ETbSame1Enum1& InProp1)
{
    TbSame1SameEnum1InterfaceTracer::trace_callSetProp1(InProp1);
    service->SetProp1(InProp1);
}

FTbSame1SameEnum1InterfaceProp1ChangedDelegate& UTbSame1SameEnum1InterfaceProxy::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}

void UTbSame1SameEnum1InterfaceProxy::Func1(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result,const ETbSame1Enum1& Param1)
{
    TbSame1SameEnum1InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FTbSame1SameEnum1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FTbSame1SameEnum1InterfaceLatentAction* CompletionAction = new FTbSame1SameEnum1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [Param1,this, &Result, CompletionAction]()
        {
            Result = service->Func1(Param1);
            CompletionAction->Cancel();
        });
	}
}
ETbSame1Enum1 UTbSame1SameEnum1InterfaceProxy::Func1(const ETbSame1Enum1& Param1)
{
    TbSame1SameEnum1InterfaceTracer::trace_callFunc1(Param1);
    return service->Func1(Param1);
}