/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesSimpleLocalIf.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbRefInterfacesSimpleLocalIfLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbRefInterfacesSimpleLocalIfLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbRefInterfacesSimpleLocalIf::UAbstractTbRefInterfacesSimpleLocalIf()
{
	TbRefInterfacesSimpleLocalIfSignals = NewObject<UTbRefInterfacesSimpleLocalIfSignals>();
}

UTbRefInterfacesSimpleLocalIfSignals* UAbstractTbRefInterfacesSimpleLocalIf::_GetSignals()
{
	if (!TbRefInterfacesSimpleLocalIfSignals)
	{
		TbRefInterfacesSimpleLocalIfSignals = NewObject<UTbRefInterfacesSimpleLocalIfSignals>();
	}
	return TbRefInterfacesSimpleLocalIfSignals;
}

int32 UAbstractTbRefInterfacesSimpleLocalIf::GetIntProperty_Private() const
{
	return GetIntProperty();
};

void UAbstractTbRefInterfacesSimpleLocalIf::SetIntProperty_Private(int32 InIntProperty)
{
	SetIntProperty(InIntProperty);
};

void UAbstractTbRefInterfacesSimpleLocalIf::IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefInterfacesSimpleLocalIfLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbRefInterfacesSimpleLocalIfLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbRefInterfacesSimpleLocalIfLatentAction* CompletionAction = new FTbRefInterfacesSimpleLocalIfLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = IntMethod(Param);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param, this, &Result, CompletionAction]()
				{
				Result = IntMethod(Param);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbRefInterfacesSimpleLocalIf::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbRefInterfacesSimpleLocalIf::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbRefInterfacesSimpleLocalIfSignals)
	{
		TbRefInterfacesSimpleLocalIfSignals->OnIntSignalSignal.RemoveAll(TbRefInterfacesSimpleLocalIfSignals);
		TbRefInterfacesSimpleLocalIfSignals->OnIntSignalSignalBP.RemoveAll(TbRefInterfacesSimpleLocalIfSignals);

		TbRefInterfacesSimpleLocalIfSignals->OnIntPropertyChanged.RemoveAll(TbRefInterfacesSimpleLocalIfSignals);
		TbRefInterfacesSimpleLocalIfSignals->OnIntPropertyChangedBP.RemoveAll(TbRefInterfacesSimpleLocalIfSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbRefInterfacesSimpleLocalIf::IsInitialized() const
{
	return bInitialized;
}
