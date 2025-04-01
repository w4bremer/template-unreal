

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Testbed2ManyParamInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceBPBase : public UObject, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2ManyParamInterfaceBPBase();

	// signals
	virtual UTestbed2ManyParamInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	int32 GetProp1_Implementation() const override;
	void SetProp1_Implementation(int32 Prop1) override;

	int32 GetProp2_Implementation() const override;
	void SetProp2_Implementation(int32 Prop2) override;

	int32 GetProp3_Implementation() const override;
	void SetProp3_Implementation(int32 Prop3) override;

	int32 GetProp4_Implementation() const override;
	void SetProp4_Implementation(int32 Prop4) override;

	// operations
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override;
	int32 Func1_Implementation(int32 Param1) override;

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override;
	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override;
	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	virtual void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop1{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(int32 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop2{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(int32 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop3{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(int32 InProp3);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp4_Private, BlueprintSetter = SetProp4_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop4{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp4_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp4_Private(int32 InProp4);

private:
	// signals
	UPROPERTY()
	UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals;
};
