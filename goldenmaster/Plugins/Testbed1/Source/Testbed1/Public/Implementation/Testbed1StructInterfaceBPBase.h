

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1StructInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructInterfaceBPBase : public UObject, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructInterfaceBPBase();

	// signals
	virtual UTestbed1StructInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	FTestbed1StructBool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FTestbed1StructString& PropString) override;

	// operations
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt) override;
	FTestbed1StructInt FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool{FTestbed1StructBool()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructBool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBool& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt{FTestbed1StructInt()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructInt GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructInt& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructFloat GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString{FTestbed1StructString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructString& InPropString);

private:
	// signals
	UPROPERTY()
	UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals;
};
