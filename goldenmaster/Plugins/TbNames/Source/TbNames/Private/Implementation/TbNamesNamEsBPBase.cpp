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

#include "Implementation/TbNamesNamEsBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

class FITbNamesNamEsInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FITbNamesNamEsInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UTbNamesNamEsSignals* UTbNamesNamEsBPBase::_GetSignals_Implementation()
{
	if (!TbNamesNamEsSignals)
	{
		TbNamesNamEsSignals = NewObject<UTbNamesNamEsSignals>();
	}
	return TbNamesNamEsSignals;
}

UTbNamesNamEsBPBase::~UTbNamesNamEsBPBase() = default;
bool UTbNamesNamEsBPBase::GetSwitch_Private() const
{
	return Execute_GetSwitch(this);
}

bool UTbNamesNamEsBPBase::GetSwitch_Implementation() const
{
	return bSwitch;
}

void UTbNamesNamEsBPBase::SetSwitch_Private(bool bInSwitch)
{
	Execute_SetSwitch(this, bInSwitch);
}

void UTbNamesNamEsBPBase::SetSwitch_Implementation(bool bInSwitch)
{
	if (bSwitch != bInSwitch)
	{
		bSwitch = bInSwitch;
		Execute__GetSignals(this)->OnSwitchChanged.Broadcast(bSwitch);
	}
}
int32 UTbNamesNamEsBPBase::GetSomeProperty_Private() const
{
	return Execute_GetSomeProperty(this);
}

int32 UTbNamesNamEsBPBase::GetSomeProperty_Implementation() const
{
	return SomeProperty;
}

void UTbNamesNamEsBPBase::SetSomeProperty_Private(int32 InSomeProperty)
{
	Execute_SetSomeProperty(this, InSomeProperty);
}

void UTbNamesNamEsBPBase::SetSomeProperty_Implementation(int32 InSomeProperty)
{
	if (SomeProperty != InSomeProperty)
	{
		SomeProperty = InSomeProperty;
		Execute__GetSignals(this)->OnSomePropertyChanged.Broadcast(SomeProperty);
	}
}
int32 UTbNamesNamEsBPBase::GetSomePoperty2_Private() const
{
	return Execute_GetSomePoperty2(this);
}

int32 UTbNamesNamEsBPBase::GetSomePoperty2_Implementation() const
{
	return SomePoperty2;
}

void UTbNamesNamEsBPBase::SetSomePoperty2_Private(int32 InSomePoperty2)
{
	Execute_SetSomePoperty2(this, InSomePoperty2);
}

void UTbNamesNamEsBPBase::SetSomePoperty2_Implementation(int32 InSomePoperty2)
{
	if (SomePoperty2 != InSomePoperty2)
	{
		SomePoperty2 = InSomePoperty2;
		Execute__GetSignals(this)->OnSomePoperty2Changed.Broadcast(SomePoperty2);
	}
}

void UTbNamesNamEsBPBase::SomeFunction_Implementation(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEsBPBase::SomeFunction2_Implementation(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}
