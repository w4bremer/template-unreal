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

#include "Implementation/TbEnumEnumInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbEnumEnumInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbEnumEnumInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbEnumEnumInterfaceSignals* UTbEnumEnumInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbEnumEnumInterfaceSignals)
	{
		TbEnumEnumInterfaceSignals = NewObject<UTbEnumEnumInterfaceSignals>();
	}
	return TbEnumEnumInterfaceSignals;
}

UTbEnumEnumInterfaceBPBase::~UTbEnumEnumInterfaceBPBase() = default;
ETbEnumEnum0 UTbEnumEnumInterfaceBPBase::GetProp0_Private() const
{
	return Execute_GetProp0(this);
}

ETbEnumEnum0 UTbEnumEnumInterfaceBPBase::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceBPBase::SetProp0_Private(ETbEnumEnum0 InProp0)
{
	Execute_SetProp0(this, InProp0);
}

void UTbEnumEnumInterfaceBPBase::SetProp0_Implementation(ETbEnumEnum0 InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		Execute__GetSignals(this)->OnProp0Changed.Broadcast(Prop0);
	}
}
ETbEnumEnum1 UTbEnumEnumInterfaceBPBase::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

ETbEnumEnum1 UTbEnumEnumInterfaceBPBase::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceBPBase::SetProp1_Private(ETbEnumEnum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
}

void UTbEnumEnumInterfaceBPBase::SetProp1_Implementation(ETbEnumEnum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
ETbEnumEnum2 UTbEnumEnumInterfaceBPBase::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

ETbEnumEnum2 UTbEnumEnumInterfaceBPBase::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceBPBase::SetProp2_Private(ETbEnumEnum2 InProp2)
{
	Execute_SetProp2(this, InProp2);
}

void UTbEnumEnumInterfaceBPBase::SetProp2_Implementation(ETbEnumEnum2 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}
ETbEnumEnum3 UTbEnumEnumInterfaceBPBase::GetProp3_Private() const
{
	return Execute_GetProp3(this);
}

ETbEnumEnum3 UTbEnumEnumInterfaceBPBase::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceBPBase::SetProp3_Private(ETbEnumEnum3 InProp3)
{
	Execute_SetProp3(this, InProp3);
}

void UTbEnumEnumInterfaceBPBase::SetProp3_Implementation(ETbEnumEnum3 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}
}

void UTbEnumEnumInterfaceBPBase::Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbEnumEnumInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbEnumEnumInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbEnumEnumInterfaceInterfaceLatentAction* CompletionAction = new FITbEnumEnumInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func0(this, Param0);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param0, this, &Result, CompletionAction]()
				{
				Result = Execute_Func0(this, Param0);
				CompletionAction->Cancel();
			});
		}
	}
}

ETbEnumEnum0 UTbEnumEnumInterfaceBPBase::Func0_Implementation(ETbEnumEnum0 Param0)
{
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::TEE0_VALUE0;
}

void UTbEnumEnumInterfaceBPBase::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbEnumEnumInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbEnumEnumInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbEnumEnumInterfaceInterfaceLatentAction* CompletionAction = new FITbEnumEnumInterfaceInterfaceLatentAction(LatentInfo);
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

ETbEnumEnum1 UTbEnumEnumInterfaceBPBase::Func1_Implementation(ETbEnumEnum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::TEE1_VALUE1;
}

void UTbEnumEnumInterfaceBPBase::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbEnumEnumInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbEnumEnumInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbEnumEnumInterfaceInterfaceLatentAction* CompletionAction = new FITbEnumEnumInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func2(this, Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param2, this, &Result, CompletionAction]()
				{
				Result = Execute_Func2(this, Param2);
				CompletionAction->Cancel();
			});
		}
	}
}

ETbEnumEnum2 UTbEnumEnumInterfaceBPBase::Func2_Implementation(ETbEnumEnum2 Param2)
{
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::TEE2_VALUE2;
}

void UTbEnumEnumInterfaceBPBase::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbEnumEnumInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbEnumEnumInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbEnumEnumInterfaceInterfaceLatentAction* CompletionAction = new FITbEnumEnumInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func3(this, Param3);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param3, this, &Result, CompletionAction]()
				{
				Result = Execute_Func3(this, Param3);
				CompletionAction->Cancel();
			});
		}
	}
}

ETbEnumEnum3 UTbEnumEnumInterfaceBPBase::Func3_Implementation(ETbEnumEnum3 Param3)
{
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::TEE3_VALUE3;
}
