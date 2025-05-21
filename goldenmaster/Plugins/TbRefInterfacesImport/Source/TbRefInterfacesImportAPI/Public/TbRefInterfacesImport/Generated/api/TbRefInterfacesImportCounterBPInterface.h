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
#include "TbRefInterfacesImportCounterInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImportCounterBPInterface.generated.h"

/**
 * Interface UTbRefInterfacesImportCounterBP only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbRefInterfacesImportCounterBP : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefInterfacesImportCounterBP
 */
class TBREFINTERFACESIMPORTAPI_API ITbRefInterfacesImportCounterBP
{
	GENERATED_BODY()

public:
	// methods

	// properties
};
