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

#include "Implementation/TbSimpleNoOperationsInterfaceBPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UTbSimpleNoOperationsInterfaceSignals* UTbSimpleNoOperationsInterfaceBPBase::_GetSignals_Implementation()
{
	if (!TbSimpleNoOperationsInterfaceSignals)
	{
		TbSimpleNoOperationsInterfaceSignals = NewObject<UTbSimpleNoOperationsInterfaceSignals>();
	}
	return TbSimpleNoOperationsInterfaceSignals;
}

UTbSimpleNoOperationsInterfaceBPBase::~UTbSimpleNoOperationsInterfaceBPBase() = default;
bool UTbSimpleNoOperationsInterfaceBPBase::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

bool UTbSimpleNoOperationsInterfaceBPBase::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoOperationsInterfaceBPBase::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
}

void UTbSimpleNoOperationsInterfaceBPBase::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}
}
int32 UTbSimpleNoOperationsInterfaceBPBase::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

int32 UTbSimpleNoOperationsInterfaceBPBase::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoOperationsInterfaceBPBase::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

void UTbSimpleNoOperationsInterfaceBPBase::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
