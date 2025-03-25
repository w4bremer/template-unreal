
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
#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesParentIf.h"
#include "TbRefInterfacesParentIfLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesParentIfLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESMONITOR_API UTbRefInterfacesParentIfLoggingDecorator : public UAbstractTbRefInterfacesParentIf
{
	GENERATED_BODY()

public:
	explicit UTbRefInterfacesParentIfLoggingDecorator();
	virtual ~UTbRefInterfacesParentIfLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	void setBackendService(TScriptInterface<ITbRefInterfacesParentIf> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetLocalIf() const override;

	void SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf) override;

	TScriptInterface<ITbRefInterfacesImportCounter> GetImportedIf() const override;

	void SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf) override;

	// operations
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param) override;

	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|ParentIf")
	TScriptInterface<ITbRefInterfacesParentIf> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InParam);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& InParam);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfChanged(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfChanged(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf);
};
