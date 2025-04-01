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

#include "Implementation/TbSame1SameStruct1InterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSame1SameStruct1InterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSame1SameStruct1InterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSame1SameStruct1InterfaceSignals* UTbSame1SameStruct1InterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSame1SameStruct1InterfaceSignals)
	{
		TbSame1SameStruct1InterfaceSignals = NewObject<UTbSame1SameStruct1InterfaceSignals>();
	}
	return TbSame1SameStruct1InterfaceSignals;
}

UTbSame1SameStruct1InterfaceBPBase::~UTbSame1SameStruct1InterfaceBPBase() = default;
FTbSame1Struct1 UTbSame1SameStruct1InterfaceBPBase::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceBPBase::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameStruct1InterfaceBPBase::SetProp1_Private(const FTbSame1Struct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

void UTbSame1SameStruct1InterfaceBPBase::SetProp1_Implementation(const FTbSame1Struct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}

void UTbSame1SameStruct1InterfaceBPBase::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSame1SameStruct1InterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSame1SameStruct1InterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSame1SameStruct1InterfaceInterfaceLatentAction* CompletionAction = new FITbSame1SameStruct1InterfaceInterfaceLatentAction(LatentInfo);
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

FTbSame1Struct1 UTbSame1SameStruct1InterfaceBPBase::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}
