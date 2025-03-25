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

#include "TbRefInterfaces/Generated/api/TbRefInterfacesParentIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbRefInterfacesParentIfOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbRefInterfacesParentIf
 * and holds the corresponding TbRefInterfacesParentIfOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBREFINTERFACESOLINK_API UTbRefInterfacesParentIfOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefInterfacesParentIfOLinkAdapter();
	virtual ~UTbRefInterfacesParentIfOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	void setBackendService(TScriptInterface<ITbRefInterfacesParentIf> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefInterfaces|ParentIf")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfChanged(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf);

	UFUNCTION(Category = "ApiGear|TbRefInterfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfChanged(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf);

	// delegate handles
	FDelegateHandle OnLocalIfChangedHandle;
	FDelegateHandle OnImportedIfChangedHandle;
	FDelegateHandle OnLocalIfSignalSignalHandle;
	FDelegateHandle OnImportedIfSignalSignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefInterfaces|ParentIf")
	TScriptInterface<ITbRefInterfacesParentIf> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbRefInterfacesParentIfOLinkSource> Source;
};
