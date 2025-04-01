

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "TbSame2SameStruct1InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameStruct1InterfaceBPBase : public UObject, public ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct1InterfaceBPBase();

	// signals
	virtual UTbSame2SameStruct1InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct1& Prop1) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct1Interface")
	FTbSame2Struct1 Prop1{FTbSame2Struct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct1& InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals;
};
