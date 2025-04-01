

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "TbSame2SameEnum2InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum2InterfaceBPBase : public UObject, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameEnum2InterfaceBPBase();

	// signals
	virtual UTbSame2SameEnum2InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame2Enum1 Prop1) override;

	ETbSame2Enum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbSame2Enum2 Prop2) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
	ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum1 Prop1{ETbSame2Enum1::TS2E1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame2Enum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum2 Prop2{ETbSame2Enum2::TS2E2_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbSame2Enum2 InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals;
};
