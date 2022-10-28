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

#include "TbSame2SameEnum1InterfaceInterface.h"
#include "olink/clientnode.h"
#include "TbSame2SameEnum1InterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum1InterfaceOLinkClient : public UObject, public ITbSame2SameEnum1InterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum1InterfaceOLinkClient();
	virtual ~UTbSame2SameEnum1InterfaceOLinkClient();

	// signals
	FTbSame2SameEnum1InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const ETbSame2Enum1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1) override{};
	ETbSame2Enum1 Func1_Implementation(const ETbSame2Enum1& Param1) override;

	// olink sink interface
	std::string olinkObjectName() override;
	void olinkOnSignal(std::string name, nlohmann::json args) override;
	void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
	void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode* node) override;
	void olinkOnRelease() override;

protected:
	// signals
	void BroadcastSig1_Implementation(const ETbSame2Enum1& Param1) override;

	void BroadcastProp1Changed_Implementation(const ETbSame2Enum1& Prop1) override;

private:
	void applyState(const nlohmann::json& fields);
	ApiGear::ObjectLink::IClientNode* m_node;
	bool m_isReady;
	// properties - local copy
	ETbSame2Enum1 Prop1{ETbSame2Enum1::VALUE1};
};
