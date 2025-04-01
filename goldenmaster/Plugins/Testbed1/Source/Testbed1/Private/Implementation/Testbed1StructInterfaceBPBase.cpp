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

#include "Implementation/Testbed1StructInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITestbed1StructInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITestbed1StructInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTestbed1StructInterfaceSignals* UTestbed1StructInterfaceBPBase::_GetSignals_Implementation()
{
	if (!Testbed1StructInterfaceSignals)
	{
		Testbed1StructInterfaceSignals = NewObject<UTestbed1StructInterfaceSignals>();
	}
	return Testbed1StructInterfaceSignals;
}

UTestbed1StructInterfaceBPBase::~UTestbed1StructInterfaceBPBase() = default;
FTestbed1StructBool UTestbed1StructInterfaceBPBase::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

FTestbed1StructBool UTestbed1StructInterfaceBPBase::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceBPBase::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
}

void UTestbed1StructInterfaceBPBase::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}
FTestbed1StructInt UTestbed1StructInterfaceBPBase::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

FTestbed1StructInt UTestbed1StructInterfaceBPBase::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceBPBase::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

void UTestbed1StructInterfaceBPBase::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
FTestbed1StructFloat UTestbed1StructInterfaceBPBase::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

FTestbed1StructFloat UTestbed1StructInterfaceBPBase::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceBPBase::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

void UTestbed1StructInterfaceBPBase::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}
FTestbed1StructString UTestbed1StructInterfaceBPBase::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

FTestbed1StructString UTestbed1StructInterfaceBPBase::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceBPBase::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

void UTestbed1StructInterfaceBPBase::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

void UTestbed1StructInterfaceBPBase::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed1StructInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed1StructInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed1StructInterfaceInterfaceLatentAction* CompletionAction = new FITestbed1StructInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, ParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamBool, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncBool(this, ParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed1StructBool UTestbed1StructInterfaceBPBase::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

void UTestbed1StructInterfaceBPBase::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed1StructInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed1StructInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed1StructInterfaceInterfaceLatentAction* CompletionAction = new FITestbed1StructInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt(this, ParamInt);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt(this, ParamInt);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed1StructInt UTestbed1StructInterfaceBPBase::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructInt();
}

void UTestbed1StructInterfaceBPBase::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed1StructInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed1StructInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed1StructInterfaceInterfaceLatentAction* CompletionAction = new FITestbed1StructInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat(this, ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat(this, ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed1StructFloat UTestbed1StructInterfaceBPBase::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

void UTestbed1StructInterfaceBPBase::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITestbed1StructInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITestbed1StructInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITestbed1StructInterfaceInterfaceLatentAction* CompletionAction = new FITestbed1StructInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncString(this, ParamString);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamString, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncString(this, ParamString);
				CompletionAction->Cancel();
			});
		}
	}
}

FTestbed1StructString UTestbed1StructInterfaceBPBase::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}
