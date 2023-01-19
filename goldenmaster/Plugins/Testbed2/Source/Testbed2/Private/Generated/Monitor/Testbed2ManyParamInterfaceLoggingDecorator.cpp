
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
#include "Generated/Monitor/Testbed2ManyParamInterfaceLoggingDecorator.h"
#include "Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed2ManyParamInterfaceLoggingDecorator);

class FTestbed2ManyParamInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2ManyParamInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
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
UTestbed2ManyParamInterfaceLoggingDecorator::UTestbed2ManyParamInterfaceLoggingDecorator()
	: ITestbed2ManyParamInterfaceInterface()
{
}

UTestbed2ManyParamInterfaceLoggingDecorator::~UTestbed2ManyParamInterfaceLoggingDecorator() = default;

void UTestbed2ManyParamInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
	BackendService->GetProp4ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
	BackendService->GetSig0SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig0);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
	BackendService->GetSig4SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetProp3ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
		BackendService->GetProp4ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
		BackendService->GetSig0SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig0);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
		BackendService->GetSig3SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
		BackendService->GetSig4SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed2ManyParamInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface Testbed2ManyParamInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
	BackendService->GetProp4ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
	BackendService->GetSig0SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig0);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
	BackendService->GetSig4SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
	Prop4 = BackendService->Execute_GetProp4(BackendService.GetObject());
}
void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastSig0_Implementation()
{
	Sig0Signal.Broadcast();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig0()
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig0();
	Execute_BroadcastSig0(this);
}

FTestbed2ManyParamInterfaceSig0Delegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastSig1_Implementation(int32 Param1)
{
	Sig1Signal.Broadcast(Param1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

FTestbed2ManyParamInterfaceSig1Delegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastSig2_Implementation(int32 Param1, int32 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute_BroadcastSig2(this, Param1, Param2);
}

FTestbed2ManyParamInterfaceSig2Delegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig3(Param1, Param2, Param3);
	Execute_BroadcastSig3(this, Param1, Param2, Param3);
}

FTestbed2ManyParamInterfaceSig3Delegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Sig4Signal.Broadcast(Param1, Param2, Param3, Param4);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig4(Param1, Param2, Param3, Param4);
	Execute_BroadcastSig4(this, Param1, Param2, Param3, Param4);
}

FTestbed2ManyParamInterfaceSig4Delegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetSig4SignalDelegate()
{
	return Sig4Signal;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastProp1Changed_Implementation(int32 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp1_Implementation(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp1_Private(int32 InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTestbed2ManyParamInterfaceProp1ChangedDelegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastProp2Changed_Implementation(int32 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp2_Implementation(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp2_Private(int32 InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTestbed2ManyParamInterfaceProp2ChangedDelegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastProp3Changed_Implementation(int32 InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute_BroadcastProp3Changed(this, InProp3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp3_Implementation(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp3_Private() const
{
	return Execute_GetProp3(this);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp3_Private(int32 InProp3)
{
	Execute_SetProp3(this, InProp3);
}

FTestbed2ManyParamInterfaceProp3ChangedDelegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::BroadcastProp4Changed_Implementation(int32 InProp4)
{
	Prop4Changed.Broadcast(InProp4);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop4 = InProp4;
	Execute_BroadcastProp4Changed(this, InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp4_Implementation() const
{
	return BackendService->Execute_GetProp4(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp4_Implementation(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp4(InProp4);
	BackendService->Execute_SetProp4(BackendService.GetObject(), InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp4_Private() const
{
	return Execute_GetProp4(this);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp4_Private(int32 InProp4)
{
	Execute_SetProp4(this, InProp4);
}

FTestbed2ManyParamInterfaceProp4ChangedDelegate& UTestbed2ManyParamInterfaceLoggingDecorator::GetProp4ChangedDelegate()
{
	return Prop4Changed;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::Func0_Implementation()
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc0();
	BackendService->Execute_Func0(BackendService.GetObject());
}
void UTestbed2ManyParamInterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func1_Implementation(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
void UTestbed2ManyParamInterfaceLoggingDecorator::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func2_Implementation(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
void UTestbed2ManyParamInterfaceLoggingDecorator::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, Param3, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
}
void UTestbed2ManyParamInterfaceLoggingDecorator::Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, Param3, Param4, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func4(BackendService.GetObject(), Param1, Param2, Param3, Param4);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);
	return BackendService->Execute_Func4(BackendService.GetObject(), Param1, Param2, Param3, Param4);
}
void UTestbed2ManyParamInterfaceLoggingDecorator::Func5_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc5(Param1, Param2, Param3, Param4, Param5);
	BackendService->Execute_Func5(BackendService.GetObject(), Param1, Param2, Param3, Param4, Param5);
}
