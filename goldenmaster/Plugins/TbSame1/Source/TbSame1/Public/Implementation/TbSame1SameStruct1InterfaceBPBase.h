

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame1SameStruct1InterfaceInterface.h"
#include "TbSame1SameStruct1InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameStruct1InterfaceBPBase : public UObject, public ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameStruct1InterfaceBPBase();

	// signals
	virtual UTbSame1SameStruct1InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	FTbSame1Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame1Struct1& Prop1) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameStruct1Interface")
	FTbSame1Struct1 Prop1{FTbSame1Struct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	FTbSame1Struct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame1Struct1& InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame1SameStruct1InterfaceSignals* TbSame1SameStruct1InterfaceSignals;
};
