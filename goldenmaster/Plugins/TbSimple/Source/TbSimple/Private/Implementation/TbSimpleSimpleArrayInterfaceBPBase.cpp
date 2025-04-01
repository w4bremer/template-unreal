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

#include "Implementation/TbSimpleSimpleArrayInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbSimpleSimpleArrayInterfaceInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbSimpleSimpleArrayInterfaceSignals* UTbSimpleSimpleArrayInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSimpleSimpleArrayInterfaceSignals)
	{
		TbSimpleSimpleArrayInterfaceSignals = NewObject<UTbSimpleSimpleArrayInterfaceSignals>();
	}
	return TbSimpleSimpleArrayInterfaceSignals;
}

UTbSimpleSimpleArrayInterfaceBPBase::~UTbSimpleSimpleArrayInterfaceBPBase() = default;
TArray<bool> UTbSimpleSimpleArrayInterfaceBPBase::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceBPBase::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt32_Private(const TArray<int32>& InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt32_Implementation(const TArray<int32>& InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(PropInt32);
	}
}
TArray<int64> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceBPBase::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt64_Private(const TArray<int64>& InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropInt64_Implementation(const TArray<int64>& InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(PropInt64);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat32_Private(const TArray<float>& InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat32_Implementation(const TArray<float>& InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(PropFloat32);
	}
}
TArray<double> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
}

TArray<double> UTbSimpleSimpleArrayInterfaceBPBase::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat64_Private(const TArray<double>& InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropFloat64_Implementation(const TArray<double>& InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(PropFloat64);
	}
}
TArray<FString> UTbSimpleSimpleArrayInterfaceBPBase::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceBPBase::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropString_Private(const TArray<FString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

void UTbSimpleSimpleArrayInterfaceBPBase::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}
FString UTbSimpleSimpleArrayInterfaceBPBase::GetPropReadOnlyString_Private() const
{
	return Execute_GetPropReadOnlyString(this);
}

FString UTbSimpleSimpleArrayInterfaceBPBase::GetPropReadOnlyString_Implementation() const
{
	return PropReadOnlyString;
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<bool> UTbSimpleSimpleArrayInterfaceBPBase::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<int32> UTbSimpleSimpleArrayInterfaceBPBase::FuncInt32_Implementation(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<int64> UTbSimpleSimpleArrayInterfaceBPBase::FuncInt64_Implementation(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<float> UTbSimpleSimpleArrayInterfaceBPBase::FuncFloat32_Implementation(const TArray<float>& ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<double> UTbSimpleSimpleArrayInterfaceBPBase::FuncFloat64_Implementation(const TArray<double>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

void UTbSimpleSimpleArrayInterfaceBPBase::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FITbSimpleSimpleArrayInterfaceInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FITbSimpleSimpleArrayInterfaceInterfaceLatentAction* CompletionAction = new FITbSimpleSimpleArrayInterfaceInterfaceLatentAction(LatentInfo);
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

TArray<FString> UTbSimpleSimpleArrayInterfaceBPBase::FuncString_Implementation(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
