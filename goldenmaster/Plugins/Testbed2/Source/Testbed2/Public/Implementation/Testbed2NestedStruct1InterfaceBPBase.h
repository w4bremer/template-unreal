

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2NestedStruct1InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2NestedStruct1InterfaceBPBase : public UObject, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2NestedStruct1InterfaceBPBase();

	// signals
	virtual UTestbed2NestedStruct1InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct1Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);

private:
	// signals
	UPROPERTY()
	UTestbed2NestedStruct1InterfaceSignals* Testbed2NestedStruct1InterfaceSignals;
};
