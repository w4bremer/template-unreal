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

#include "Implementation/Testbed2ManyParamInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITestbed2ManyParamInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITestbed2ManyParamInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTestbed2ManyParamInterfaceSignals* UTestbed2ManyParamInterfaceBPBase::_GetSignals_Implementation()
{
	if (!Testbed2ManyParamInterfaceSignals)
	{
		Testbed2ManyParamInterfaceSignals = NewObject<UTestbed2ManyParamInterfaceSignals>();
	}
	return Testbed2ManyParamInterfaceSignals;
}

UTestbed2ManyParamInterfaceBPBase::~UTestbed2ManyParamInterfaceBPBase() = default;
int32 UTestbed2ManyParamInterfaceBPBase::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

int32 UTestbed2ManyParamInterfaceBPBase::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceBPBase::SetProp1_Private(int32 InProp1)
{
	Execute_SetProp1(this, InProp1);
}

void UTestbed2ManyParamInterfaceBPBase::SetProp1_Implementation(int32 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
int32 UTestbed2ManyParamInterfaceBPBase::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

int32 UTestbed2ManyParamInterfaceBPBase::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceBPBase::SetProp2_Private(int32 InProp2)
{
	Execute_SetProp2(this, InProp2);
}

void UTestbed2ManyParamInterfaceBPBase::SetProp2_Implementation(int32 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}
int32 UTestbed2ManyParamInterfaceBPBase::GetProp3_Private() const
{
	return Execute_GetProp3(this);
}

int32 UTestbed2ManyParamInterfaceBPBase::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceBPBase::SetProp3_Private(int32 InProp3)
{
	Execute_SetProp3(this, InProp3);
}

void UTestbed2ManyParamInterfaceBPBase::SetProp3_Implementation(int32 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}
}
int32 UTestbed2ManyParamInterfaceBPBase::GetProp4_Private() const
{
	return Execute_GetProp4(this);
}

int32 UTestbed2ManyParamInterfaceBPBase::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceBPBase::SetProp4_Private(int32 InProp4)
{
	Execute_SetProp4(this, InProp4);
}

void UTestbed2ManyParamInterfaceBPBase::SetProp4_Implementation(int32 InProp4)
{
	if (Prop4 != InProp4)
	{
		Prop4 = InProp4;
		Execute__GetSignals(this)->OnProp4Changed.Broadcast(Prop4);
	}
}

void UTestbed2ManyParamInterfaceBPBase::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2ManyParamInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2ManyParamInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2ManyParamInterfaceInterfaceLatentAction* CompletionAction = new FITestbed2ManyParamInterfaceInterfaceLatentAction(LatentInfo);
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

int32 UTestbed2ManyParamInterfaceBPBase::Func1_Implementation(int32 Param1)
{
	(void)Param1;
	// do business logic here
	return 0;
}

void UTestbed2ManyParamInterfaceBPBase::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2ManyParamInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2ManyParamInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2ManyParamInterfaceInterfaceLatentAction* CompletionAction = new FITestbed2ManyParamInterfaceInterfaceLatentAction(LatentInfo);
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

int32 UTestbed2ManyParamInterfaceBPBase::Func2_Implementation(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return 0;
}

void UTestbed2ManyParamInterfaceBPBase::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2ManyParamInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2ManyParamInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2ManyParamInterfaceInterfaceLatentAction* CompletionAction = new FITestbed2ManyParamInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func3(this, Param1, Param2, Param3);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, Param3, this, &Result, CompletionAction]()
				{
				Result = Execute_Func3(this, Param1, Param2, Param3);
				CompletionAction->Cancel();
			});
		}
	}
}

int32 UTestbed2ManyParamInterfaceBPBase::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return 0;
}

void UTestbed2ManyParamInterfaceBPBase::Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed2ManyParamInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed2ManyParamInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed2ManyParamInterfaceInterfaceLatentAction* CompletionAction = new FITestbed2ManyParamInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func4(this, Param1, Param2, Param3, Param4);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, Param3, Param4, this, &Result, CompletionAction]()
				{
				Result = Execute_Func4(this, Param1, Param2, Param3, Param4);
				CompletionAction->Cancel();
			});
		}
	}
}

int32 UTestbed2ManyParamInterfaceBPBase::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
	// do business logic here
	return 0;
}
