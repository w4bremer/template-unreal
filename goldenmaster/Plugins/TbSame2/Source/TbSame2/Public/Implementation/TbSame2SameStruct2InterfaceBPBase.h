

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "TbSame2SameStruct2InterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameStruct2InterfaceBPBase : public UObject, public ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct2InterfaceBPBase();

	// signals
	virtual UTbSame2SameStruct2InterfaceSignals* _GetSignals_Implementation() override;

	// properties
	FTbSame2Struct2 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct2& Prop1) override;

	FTbSame2Struct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTbSame2Struct2& Prop2) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame2Struct2& InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals;
};
