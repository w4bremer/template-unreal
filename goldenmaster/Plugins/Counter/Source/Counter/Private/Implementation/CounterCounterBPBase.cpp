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

#include "Implementation/CounterCounterBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FICounterCounterInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FICounterCounterInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UCounterCounterSignals* UCounterCounterBPBase::_GetSignals_Implementation()
{
	if (!CounterCounterSignals)
	{
		CounterCounterSignals = NewObject<UCounterCounterSignals>();
	}
	return CounterCounterSignals;
}

UCounterCounterBPBase::~UCounterCounterBPBase() = default;
FCustomTypesVector3D UCounterCounterBPBase::GetVector_Private() const
{
	return Execute_GetVector(this);
}

FCustomTypesVector3D UCounterCounterBPBase::GetVector_Implementation() const
{
	return Vector;
}

void UCounterCounterBPBase::SetVector_Private(const FCustomTypesVector3D& InVector)
{
	Execute_SetVector(this, InVector);
}

void UCounterCounterBPBase::SetVector_Implementation(const FCustomTypesVector3D& InVector)
{
	if (Vector != InVector)
	{
		Vector = InVector;
		Execute__GetSignals(this)->OnVectorChanged.Broadcast(Vector);
	}
}
FVector UCounterCounterBPBase::GetExternVector_Private() const
{
	return Execute_GetExternVector(this);
}

FVector UCounterCounterBPBase::GetExternVector_Implementation() const
{
	return ExternVector;
}

void UCounterCounterBPBase::SetExternVector_Private(const FVector& InExternVector)
{
	Execute_SetExternVector(this, InExternVector);
}

void UCounterCounterBPBase::SetExternVector_Implementation(const FVector& InExternVector)
{
	if (ExternVector != InExternVector)
	{
		ExternVector = InExternVector;
		Execute__GetSignals(this)->OnExternVectorChanged.Broadcast(ExternVector);
	}
}
TArray<FCustomTypesVector3D> UCounterCounterBPBase::GetVectorArray_Private() const
{
	return Execute_GetVectorArray(this);
}

TArray<FCustomTypesVector3D> UCounterCounterBPBase::GetVectorArray_Implementation() const
{
	return VectorArray;
}

void UCounterCounterBPBase::SetVectorArray_Private(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	Execute_SetVectorArray(this, InVectorArray);
}

void UCounterCounterBPBase::SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (VectorArray != InVectorArray)
	{
		VectorArray = InVectorArray;
		Execute__GetSignals(this)->OnVectorArrayChanged.Broadcast(VectorArray);
	}
}
TArray<FVector> UCounterCounterBPBase::GetExternVectorArray_Private() const
{
	return Execute_GetExternVectorArray(this);
}

TArray<FVector> UCounterCounterBPBase::GetExternVectorArray_Implementation() const
{
	return ExternVectorArray;
}

void UCounterCounterBPBase::SetExternVectorArray_Private(const TArray<FVector>& InExternVectorArray)
{
	Execute_SetExternVectorArray(this, InExternVectorArray);
}

void UCounterCounterBPBase::SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray)
{
	if (ExternVectorArray != InExternVectorArray)
	{
		ExternVectorArray = InExternVectorArray;
		Execute__GetSignals(this)->OnExternVectorArrayChanged.Broadcast(ExternVectorArray);
	}
}

void UCounterCounterBPBase::IncrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FICounterCounterInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FICounterCounterInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FICounterCounterInterfaceLatentAction* CompletionAction = new FICounterCounterInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Increment(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_Increment(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

FVector UCounterCounterBPBase::Increment_Implementation(const FVector& Vec)
{
	(void)Vec;
	// do business logic here
	return FVector(0.f, 0.f, 0.f);
}

void UCounterCounterBPBase::IncrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FICounterCounterInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FICounterCounterInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FICounterCounterInterfaceLatentAction* CompletionAction = new FICounterCounterInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_IncrementArray(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_IncrementArray(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

TArray<FVector> UCounterCounterBPBase::IncrementArray_Implementation(const TArray<FVector>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FVector>();
}

void UCounterCounterBPBase::DecrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FICounterCounterInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FICounterCounterInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FICounterCounterInterfaceLatentAction* CompletionAction = new FICounterCounterInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Decrement(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_Decrement(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

FCustomTypesVector3D UCounterCounterBPBase::Decrement_Implementation(const FCustomTypesVector3D& Vec)
{
	(void)Vec;
	// do business logic here
	return FCustomTypesVector3D();
}

void UCounterCounterBPBase::DecrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FICounterCounterInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FICounterCounterInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FICounterCounterInterfaceLatentAction* CompletionAction = new FICounterCounterInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_DecrementArray(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_DecrementArray(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

TArray<FCustomTypesVector3D> UCounterCounterBPBase::DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FCustomTypesVector3D>();
}
