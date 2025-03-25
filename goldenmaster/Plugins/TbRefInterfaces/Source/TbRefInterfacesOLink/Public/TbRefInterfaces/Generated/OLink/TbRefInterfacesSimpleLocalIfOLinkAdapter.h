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

#include "TbRefInterfaces/Generated/api/TbRefInterfacesSimpleLocalIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbRefInterfacesSimpleLocalIfOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbRefInterfacesSimpleLocalIf
 * and holds the corresponding TbRefInterfacesSimpleLocalIfOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBREFINTERFACESOLINK_API UTbRefInterfacesSimpleLocalIfOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesSimpleLocalIfOLinkAdapter();
	virtual ~UTbRefInterfacesSimpleLocalIfOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	void setBackendService(TScriptInterface<ITbRefInterfacesSimpleLocalIf> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntSignal(int32 Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntPropertyChanged(int32 IntProperty);

	// delegate handles
	FDelegateHandle OnIntPropertyChangedHandle;
	FDelegateHandle OnIntSignalSignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|SimpleLocalIf")
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbRefInterfacesSimpleLocalIfOLinkSource> Source;
};
