

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "TbSame1SameEnum2InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum2InterfaceBPBase : public UObject, public ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameEnum2InterfaceBPBase();

	// signals
	virtual UTbSame1SameEnum2InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame1Enum1 Prop1) override;

	ETbSame1Enum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbSame1Enum2 Prop2) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;
	ETbSame1Enum1 Func2_Implementation(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum2Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TS1E1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame1|SameEnum2Interface")
	ETbSame1Enum2 Prop2{ETbSame1Enum2::TS1E2_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbSame1Enum2 InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals;
};
