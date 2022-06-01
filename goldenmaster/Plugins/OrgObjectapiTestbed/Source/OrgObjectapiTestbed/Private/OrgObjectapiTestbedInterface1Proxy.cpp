
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
#include "OrgObjectapiTestbedInterface1Proxy.h"
#include "Interface1/OrgObjectapiTestbedInterface1Local.h"
#include "apig/OrgObjectapiTestbed.trace.h"
#include "OrgObjectapiTestbedFactory.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FOrgObjectapiTestbedInterface1LatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FOrgObjectapiTestbedInterface1LatentAction(const FLatentActionInfo& LatentInfo)
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
UOrgObjectapiTestbedInterface1Proxy::UOrgObjectapiTestbedInterface1Proxy()
    : IOrgObjectapiTestbedInterface1Interface()
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
    service = FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface1Interface();

    service->SubscribeToOrgObjectapiTestbedInterface1StateChanged(*this);
    service->SubscribeToSig1(*this);
    service->SubscribeToSig2(*this);
    service->SubscribeToSig3(*this);
}

UOrgObjectapiTestbedInterface1Proxy::~UOrgObjectapiTestbedInterface1Proxy()
{
    service->UnsubscribeFromOrgObjectapiTestbedInterface1StateChanged(*this);
    service->UnsubscribeFromSig1(*this);
    service->UnsubscribeFromSig2(*this);
    service->UnsubscribeFromSig3(*this);
}
void UOrgObjectapiTestbedInterface1Proxy::OnSig1()
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig1();
    Sig1Signal.Broadcast();
}
void UOrgObjectapiTestbedInterface1Proxy::OnSig2(int32 Step)
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig2(Step);
    Sig2Signal.Broadcast(Step);
}
void UOrgObjectapiTestbedInterface1Proxy::OnSig3()
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig3();
    Sig3Signal.Broadcast();
}
void UOrgObjectapiTestbedInterface1Proxy::OnbProp1Changed(bool Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    bProp1Changed.Broadcast(Value);
}

bool UOrgObjectapiTestbedInterface1Proxy::GetProp1() const
{
    return service->GetProp1();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp1(bool Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp1(Value);
    service->SetProp1(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp2Changed(int32 Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop2Changed.Broadcast(Value);
}

int32 UOrgObjectapiTestbedInterface1Proxy::GetProp2() const
{
    return service->GetProp2();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp2(int32 Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp2(Value);
    service->SetProp2(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp3Changed(float Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop3Changed.Broadcast(Value);
}

float UOrgObjectapiTestbedInterface1Proxy::GetProp3() const
{
    return service->GetProp3();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp3(float Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp3(Value);
    service->SetProp3(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp4Changed(FString Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop4Changed.Broadcast(Value);
}

FString UOrgObjectapiTestbedInterface1Proxy::GetProp4() const
{
    return service->GetProp4();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp4(FString Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp4(Value);
    service->SetProp4(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp5Changed(TArray<int32> Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop5Changed.Broadcast(Value);
}

TArray<int32> UOrgObjectapiTestbedInterface1Proxy::GetProp5() const
{
    return service->GetProp5();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp5(TArray<int32> Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp5(Value);
    service->SetProp5(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp6Changed(const FStruct1& Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop6Changed.Broadcast(Value);
}

FStruct1 UOrgObjectapiTestbedInterface1Proxy::GetProp6() const
{
    return service->GetProp6();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp6(const FStruct1& Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp6(Value);
    service->SetProp6(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp7Changed(int32 Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop7Changed.Broadcast(Value);
}

int32 UOrgObjectapiTestbedInterface1Proxy::GetProp7() const
{
    return service->GetProp7();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp7(int32 Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp7(Value);
    service->SetProp7(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp10Changed(TArray<int32> Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop10Changed.Broadcast(Value);
}

TArray<int32> UOrgObjectapiTestbedInterface1Proxy::GetProp10() const
{
    return service->GetProp10();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp10(TArray<int32> Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp10(Value);
    service->SetProp10(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp11Changed(const TArray<FStruct1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop11Changed.Broadcast(Value);
}

TArray<FStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp11() const
{
    return service->GetProp11();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp11(const TArray<FStruct1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp11(Value);
    service->SetProp11(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp12Changed(const TArray<EEnum1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop12Changed.Broadcast(Value);
}

TArray<EEnum1> UOrgObjectapiTestbedInterface1Proxy::GetProp12() const
{
    return service->GetProp12();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp12(const TArray<EEnum1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp12(Value);
    service->SetProp12(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp14Changed(const TArray<FStruct1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop14Changed.Broadcast(Value);
}

TArray<FStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp14() const
{
    return service->GetProp14();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp14(const TArray<FStruct1>& Value)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp14(Value);
    service->SetProp14(Value);
}

void UOrgObjectapiTestbedInterface1Proxy::Op1()
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp1();
    service->Op1();
}
void UOrgObjectapiTestbedInterface1Proxy::Op2(int32 Step)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp2(Step);
    service->Op2(Step);
}
void UOrgObjectapiTestbedInterface1Proxy::Op3(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp3();

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FOrgObjectapiTestbedInterface1LatentAction* oldRequest = LatentActionManager.FindExistingAction<FOrgObjectapiTestbedInterface1LatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FOrgObjectapiTestbedInterface1LatentAction* CompletionAction = new FOrgObjectapiTestbedInterface1LatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [this, &Result, CompletionAction]()
        {
            Result = service->Op3();
            CompletionAction->Cancel();
        });
	}
}
int32 UOrgObjectapiTestbedInterface1Proxy::Op3()
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp3();
    return service->Op3();
}
