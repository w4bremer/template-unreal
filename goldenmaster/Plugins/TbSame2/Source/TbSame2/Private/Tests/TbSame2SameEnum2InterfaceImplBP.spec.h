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
#pragma once

#include "Implementation/TbSame2SameEnum2InterfaceBPBase.h"
#include "TbSame2SameEnum2InterfaceImplBPFixture.h"
#include "TbSame2TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame2SameEnum2InterfaceBPBaseImplSpec, "TbSame2.SameEnum2Interface.Impl", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameEnum2InterfaceImplBPFixture> ImplBPFixture;

// signal callbacks for testing
void Prop1PropertyCb(ETbSame2Enum1 Prop1);
void Prop2PropertyCb(ETbSame2Enum2 Prop2);
void Sig1SignalCb(ETbSame2Enum1 Param1);
void Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
FDoneDelegate testDoneDelegate;

friend class UTbSame2SameEnum2InterfaceBPBaseImplHelper;
END_DEFINE_SPEC(UTbSame2SameEnum2InterfaceBPBaseImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
