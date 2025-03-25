
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

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefInterfacesImport/Generated/api/AbstractTbRefInterfacesImportCounter.h"
#include "TbRefInterfacesImportCounterLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesImportCounterLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESIMPORTMONITOR_API UTbRefInterfacesImportCounterLoggingDecorator : public UAbstractTbRefInterfacesImportCounter
{
	GENERATED_BODY()

public:
	explicit UTbRefInterfacesImportCounterLoggingDecorator();
	virtual ~UTbRefInterfacesImportCounterLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfacesImport|Counter")
	void setBackendService(TScriptInterface<ITbRefInterfacesImportCounter> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	// operations
private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfacesImport|Counter")
	TScriptInterface<ITbRefInterfacesImportCounter> BackendService;

	// signals
};
