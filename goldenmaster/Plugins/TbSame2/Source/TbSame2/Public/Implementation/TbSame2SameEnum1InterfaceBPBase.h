

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "TbSame2SameEnum1InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum1InterfaceBPBase : public UObject, public ITbSame2SameEnum1InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameEnum1InterfaceBPBase();

	// signals
	virtual UTbSame2SameEnum1InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame2Enum1 Prop1) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum1Interface")
	ETbSame2Enum1 Prop1{ETbSame2Enum1::TS2E1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame2Enum1 InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals;
};
