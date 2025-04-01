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

#include "Implementation/Testbed2NestedStruct2InterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITestbed2NestedStruct2InterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITestbed2NestedStruct2InterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTestbed2NestedStruct2InterfaceSignals* UTestbed2NestedStruct2InterfaceBPBase::_GetSignals_Implementation()
{
	if (!Testbed2NestedStruct2InterfaceSignals)
	{
		Testbed2NestedStruct2InterfaceSignals = NewObject<UTestbed2NestedStruct2InterfaceSignals>();
	}
	return Testbed2NestedStruct2InterfaceSignals;
}

UTestbed2NestedStruct2InterfaceBPBase::~UTestbed2NestedStruct2InterfaceBPBase() = default;
FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPBase::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPBase::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct2InterfaceBPBase::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

void UTestbed2NestedStruct2InterfaceBPBase::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceBPBase::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceBPBase::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2NestedStruct2InterfaceBPBase::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

void UTestbed2NestedStruct2InterfaceBPBase::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

void UTestbed2NestedStruct2InterfaceBPBase::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2NestedStruct2InterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2NestedStruct2InterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2NestedStruct2InterfaceInterfaceLatentAction* CompletionAction = new FITestbed2NestedStruct2InterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func1(this, Param1);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, this, &Result, CompletionAction]()
				{
				Result = Execute_Func1(this, Param1);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPBase::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct2InterfaceBPBase::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2NestedStruct2InterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2NestedStruct2InterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2NestedStruct2InterfaceInterfaceLatentAction* CompletionAction = new FITestbed2NestedStruct2InterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func2(this, Param1, Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, this, &Result, CompletionAction]()
				{
				Result = Execute_Func2(this, Param1, Param2);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPBase::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTestbed2NestedStruct1();
}
