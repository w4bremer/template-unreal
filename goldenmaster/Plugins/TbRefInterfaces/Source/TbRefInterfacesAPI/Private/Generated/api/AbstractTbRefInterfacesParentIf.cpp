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
#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesParentIf.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbRefInterfacesParentIfLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbRefInterfacesParentIfLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbRefInterfacesParentIf::UAbstractTbRefInterfacesParentIf()
{
	TbRefInterfacesParentIfSignals = NewObject<UTbRefInterfacesParentIfSignals>();
}

UTbRefInterfacesParentIfSignals* UAbstractTbRefInterfacesParentIf::_GetSignals()
{
	if (!TbRefInterfacesParentIfSignals)
	{
		TbRefInterfacesParentIfSignals = NewObject<UTbRefInterfacesParentIfSignals>();
	}
	return TbRefInterfacesParentIfSignals;
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> UAbstractTbRefInterfacesParentIf::GetLocalIf_Private() const
{
	return GetLocalIf();
};

void UAbstractTbRefInterfacesParentIf::SetLocalIf_Private(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	SetLocalIf(InLocalIf);
};

TScriptInterface<ITbRefInterfacesImportCounter> UAbstractTbRefInterfacesParentIf::GetImportedIf_Private() const
{
	return GetImportedIf();
};

void UAbstractTbRefInterfacesParentIf::SetImportedIf_Private(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	SetImportedIf(InImportedIf);
};

void UAbstractTbRefInterfacesParentIf::LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Result, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefInterfacesParentIfLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbRefInterfacesParentIfLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbRefInterfacesParentIfLatentAction* CompletionAction = new FTbRefInterfacesParentIfLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = LocalIfMethod(Param);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param, this, &Result, CompletionAction]()
				{
				Result = LocalIfMethod(Param);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbRefInterfacesParentIf::ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefInterfacesImportCounter>& Result, const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefInterfacesParentIfLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbRefInterfacesParentIfLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbRefInterfacesParentIfLatentAction* CompletionAction = new FTbRefInterfacesParentIfLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = ImportedIfMethod(Param);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param, this, &Result, CompletionAction]()
				{
				Result = ImportedIfMethod(Param);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbRefInterfacesParentIf::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbRefInterfacesParentIf::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbRefInterfacesParentIfSignals)
	{
		TbRefInterfacesParentIfSignals->OnLocalIfSignalSignal.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnLocalIfSignalSignalBP.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnImportedIfSignalSignal.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnImportedIfSignalSignalBP.RemoveAll(TbRefInterfacesParentIfSignals);

		TbRefInterfacesParentIfSignals->OnLocalIfChanged.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnLocalIfChangedBP.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnImportedIfChanged.RemoveAll(TbRefInterfacesParentIfSignals);
		TbRefInterfacesParentIfSignals->OnImportedIfChangedBP.RemoveAll(TbRefInterfacesParentIfSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbRefInterfacesParentIf::IsInitialized() const
{
	return bInitialized;
}
