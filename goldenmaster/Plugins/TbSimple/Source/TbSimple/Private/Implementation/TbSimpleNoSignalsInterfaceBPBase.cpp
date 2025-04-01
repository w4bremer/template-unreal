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

#include "Implementation/TbSimpleNoSignalsInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSimpleNoSignalsInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSimpleNoSignalsInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSimpleNoSignalsInterfaceSignals* UTbSimpleNoSignalsInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSimpleNoSignalsInterfaceSignals)
	{
		TbSimpleNoSignalsInterfaceSignals = NewObject<UTbSimpleNoSignalsInterfaceSignals>();
	}
	return TbSimpleNoSignalsInterfaceSignals;
}

UTbSimpleNoSignalsInterfaceBPBase::~UTbSimpleNoSignalsInterfaceBPBase() = default;
bool UTbSimpleNoSignalsInterfaceBPBase::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

bool UTbSimpleNoSignalsInterfaceBPBase::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoSignalsInterfaceBPBase::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
}

void UTbSimpleNoSignalsInterfaceBPBase::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}
}
int32 UTbSimpleNoSignalsInterfaceBPBase::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

int32 UTbSimpleNoSignalsInterfaceBPBase::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoSignalsInterfaceBPBase::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

void UTbSimpleNoSignalsInterfaceBPBase::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceBPBase::FuncVoid_Implementation()
{
	// do business logic here
}

void UTbSimpleNoSignalsInterfaceBPBase::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleNoSignalsInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleNoSignalsInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleNoSignalsInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleNoSignalsInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, bParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[bParamBool, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncBool(this, bParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

bool UTbSimpleNoSignalsInterfaceBPBase::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}
