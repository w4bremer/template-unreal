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

#include "Implementation/TbSimpleNoPropertiesInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSimpleNoPropertiesInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSimpleNoPropertiesInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSimpleNoPropertiesInterfaceSignals* UTbSimpleNoPropertiesInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSimpleNoPropertiesInterfaceSignals)
	{
		TbSimpleNoPropertiesInterfaceSignals = NewObject<UTbSimpleNoPropertiesInterfaceSignals>();
	}
	return TbSimpleNoPropertiesInterfaceSignals;
}

UTbSimpleNoPropertiesInterfaceBPBase::~UTbSimpleNoPropertiesInterfaceBPBase() = default;

void UTbSimpleNoPropertiesInterfaceBPBase::FuncVoid_Implementation()
{
	// do business logic here
}

void UTbSimpleNoPropertiesInterfaceBPBase::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleNoPropertiesInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleNoPropertiesInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleNoPropertiesInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleNoPropertiesInterfaceInterfaceLatentAction(LatentInfo);
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

bool UTbSimpleNoPropertiesInterfaceBPBase::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}
