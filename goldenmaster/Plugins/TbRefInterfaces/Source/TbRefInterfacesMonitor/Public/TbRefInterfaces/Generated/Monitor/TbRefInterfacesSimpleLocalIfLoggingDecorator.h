
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
#include "TbRefInterfaces/Generated/api/AbstractTbRefInterfacesSimpleLocalIf.h"
#include "TbRefInterfacesSimpleLocalIfLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefInterfacesSimpleLocalIfLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFINTERFACESMONITOR_API UTbRefInterfacesSimpleLocalIfLoggingDecorator : public UAbstractTbRefInterfacesSimpleLocalIf
{
	GENERATED_BODY()

public:
	explicit UTbRefInterfacesSimpleLocalIfLoggingDecorator();
	virtual ~UTbRefInterfacesSimpleLocalIfLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	void setBackendService(TScriptInterface<ITbRefInterfacesSimpleLocalIf> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	int32 GetIntProperty() const override;

	void SetIntProperty(int32 InIntProperty) override;

	// operations
	int32 IntMethod(int32 Param) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntSignal(int32 InParam);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntPropertyChanged(int32 InIntProperty);
};
