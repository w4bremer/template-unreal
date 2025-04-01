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

#include "Implementation/TbSame2SameStruct2InterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSame2SameStruct2InterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSame2SameStruct2InterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSame2SameStruct2InterfaceSignals* UTbSame2SameStruct2InterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSame2SameStruct2InterfaceSignals)
	{
		TbSame2SameStruct2InterfaceSignals = NewObject<UTbSame2SameStruct2InterfaceSignals>();
	}
	return TbSame2SameStruct2InterfaceSignals;
}

UTbSame2SameStruct2InterfaceBPBase::~UTbSame2SameStruct2InterfaceBPBase() = default;
FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPBase::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPBase::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameStruct2InterfaceBPBase::SetProp1_Private(const FTbSame2Struct2& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

void UTbSame2SameStruct2InterfaceBPBase::SetProp1_Implementation(const FTbSame2Struct2& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPBase::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPBase::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame2SameStruct2InterfaceBPBase::SetProp2_Private(const FTbSame2Struct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

void UTbSame2SameStruct2InterfaceBPBase::SetProp2_Implementation(const FTbSame2Struct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

void UTbSame2SameStruct2InterfaceBPBase::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSame2SameStruct2InterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSame2SameStruct2InterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSame2SameStruct2InterfaceInterfaceLatentAction* CompletionAction = new FITbSame2SameStruct2InterfaceInterfaceLatentAction(LatentInfo);
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

FTbSame2Struct1 UTbSame2SameStruct2InterfaceBPBase::Func1_Implementation(const FTbSame2Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

void UTbSame2SameStruct2InterfaceBPBase::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSame2SameStruct2InterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSame2SameStruct2InterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSame2SameStruct2InterfaceInterfaceLatentAction* CompletionAction = new FITbSame2SameStruct2InterfaceInterfaceLatentAction(LatentInfo);
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

FTbSame2Struct1 UTbSame2SameStruct2InterfaceBPBase::Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame2Struct1();
}
