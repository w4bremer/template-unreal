

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1SameEnum1InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum1InterfaceBPBase : public UObject, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameEnum1InterfaceBPBase();

	// signals
	virtual UTbSame1SameEnum1InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame1Enum1 Prop1) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TS1E1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals;
};
