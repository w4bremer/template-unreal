

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbEnumEnumInterfaceInterface.h"
#include "TbEnumEnumInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBENUM_API UTbEnumEnumInterfaceBPBase : public UObject, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbEnumEnumInterfaceBPBase();

	// signals
	virtual UTbEnumEnumInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	ETbEnumEnum0 GetProp0_Implementation() const override;
	void SetProp0_Implementation(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;
	void SetProp3_Implementation(ETbEnumEnum3 Prop3) override;

	// operations
	virtual void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override;
	ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override;

	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override;
	ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override;

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override;
	ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override;

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override;
	ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0_Private, BlueprintSetter = SetProp0_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0{ETbEnumEnum0::TEE0_VALUE0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum0 GetProp0_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp0_Private(ETbEnumEnum0 InProp0);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1{ETbEnumEnum1::TEE1_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbEnumEnum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2{ETbEnumEnum2::TEE2_VALUE2};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbEnumEnum2 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3{ETbEnumEnum3::TEE3_VALUE3};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(ETbEnumEnum3 InProp3);

private:
	// signals
	UPROPERTY()
	UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals;
};
