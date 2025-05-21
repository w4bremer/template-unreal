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
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImportCounterInterface.h"
#include "AbstractTbRefInterfacesImportCounter.generated.h"

/**
 * Abstract UAbstractTbRefInterfacesImportCounter
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBREFINTERFACESIMPORTAPI_API UAbstractTbRefInterfacesImportCounter : public UGameInstanceSubsystem, public ITbRefInterfacesImportCounter
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbRefInterfacesImportCounter();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// methods

	// properties

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy

private:
};
