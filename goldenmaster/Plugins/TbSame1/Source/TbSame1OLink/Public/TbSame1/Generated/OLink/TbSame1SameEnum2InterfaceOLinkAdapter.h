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

#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbSame1SameEnum2InterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbSame1SameEnum2Interface
 * and holds the corresponding TbSame1SameEnum2InterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBSAME1OLINK_API UTbSame1SameEnum2InterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum2InterfaceOLinkAdapter();
	virtual ~UTbSame1SameEnum2InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum2Interface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbSame1Enum2 Prop2);

	// delegate handles
	FDelegateHandle OnProp1ChangedHandle;
	FDelegateHandle OnProp2ChangedHandle;
	FDelegateHandle OnSig1SignalHandle;
	FDelegateHandle OnSig2SignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2Interface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSame1SameEnum2InterfaceOLinkSource> Source;
};
