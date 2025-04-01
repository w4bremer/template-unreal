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

#include "Implementation/TbSimpleSimpleInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSimpleSimpleInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSimpleSimpleInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSimpleSimpleInterfaceSignals* UTbSimpleSimpleInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSimpleSimpleInterfaceSignals)
	{
		TbSimpleSimpleInterfaceSignals = NewObject<UTbSimpleSimpleInterfaceSignals>();
	}
	return TbSimpleSimpleInterfaceSignals;
}

UTbSimpleSimpleInterfaceBPBase::~UTbSimpleSimpleInterfaceBPBase() = default;
bool UTbSimpleSimpleInterfaceBPBase::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

bool UTbSimpleSimpleInterfaceBPBase::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}
}
int32 UTbSimpleSimpleInterfaceBPBase::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

int32 UTbSimpleSimpleInterfaceBPBase::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
int32 UTbSimpleSimpleInterfaceBPBase::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
}

int32 UTbSimpleSimpleInterfaceBPBase::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt32_Private(int32 InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt32_Implementation(int32 InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(PropInt32);
	}
}
int64 UTbSimpleSimpleInterfaceBPBase::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
}

int64 UTbSimpleSimpleInterfaceBPBase::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt64_Private(int64 InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropInt64_Implementation(int64 InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(PropInt64);
	}
}
float UTbSimpleSimpleInterfaceBPBase::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

float UTbSimpleSimpleInterfaceBPBase::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat_Private(float InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat_Implementation(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}
float UTbSimpleSimpleInterfaceBPBase::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
}

float UTbSimpleSimpleInterfaceBPBase::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat32_Private(float InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat32_Implementation(float InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(PropFloat32);
	}
}
double UTbSimpleSimpleInterfaceBPBase::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
}

double UTbSimpleSimpleInterfaceBPBase::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat64_Private(double InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropFloat64_Implementation(double InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(PropFloat64);
	}
}
FString UTbSimpleSimpleInterfaceBPBase::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

FString UTbSimpleSimpleInterfaceBPBase::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterfaceBPBase::SetPropString_Private(const FString& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

void UTbSimpleSimpleInterfaceBPBase::SetPropString_Implementation(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

void UTbSimpleSimpleInterfaceBPBase::FuncNoReturnValue_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
}

void UTbSimpleSimpleInterfaceBPBase::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
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

bool UTbSimpleSimpleInterfaceBPBase::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}

void UTbSimpleSimpleInterfaceBPBase::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
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

int32 UTbSimpleSimpleInterfaceBPBase::FuncInt_Implementation(int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return 0;
}

void UTbSimpleSimpleInterfaceBPBase::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt32(this, ParamInt32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt32, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt32(this, ParamInt32);
				CompletionAction->Cancel();
			});
		}
	}
}

int32 UTbSimpleSimpleInterfaceBPBase::FuncInt32_Implementation(int32 ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return 0;
}

void UTbSimpleSimpleInterfaceBPBase::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt64(this, ParamInt64);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt64, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt64(this, ParamInt64);
				CompletionAction->Cancel();
			});
		}
	}
}

int64 UTbSimpleSimpleInterfaceBPBase::FuncInt64_Implementation(int64 ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return 0LL;
}

void UTbSimpleSimpleInterfaceBPBase::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
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

float UTbSimpleSimpleInterfaceBPBase::FuncFloat_Implementation(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

void UTbSimpleSimpleInterfaceBPBase::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat32(this, ParamFloat32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat32, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat32(this, ParamFloat32);
				CompletionAction->Cancel();
			});
		}
	}
}

float UTbSimpleSimpleInterfaceBPBase::FuncFloat32_Implementation(float ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return 0.0f;
}

void UTbSimpleSimpleInterfaceBPBase::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat64(this, ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat64(this, ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

double UTbSimpleSimpleInterfaceBPBase::FuncFloat64_Implementation(double ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0;
}

void UTbSimpleSimpleInterfaceBPBase::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleInterfaceInterfaceLatentAction(LatentInfo);
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

FString UTbSimpleSimpleInterfaceBPBase::FuncString_Implementation(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}
