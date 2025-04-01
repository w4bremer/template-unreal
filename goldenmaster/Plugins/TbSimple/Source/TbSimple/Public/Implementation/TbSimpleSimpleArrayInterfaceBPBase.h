

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimpleSimpleArrayInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceBPBase : public UObject, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleArrayInterfaceBPBase();

	// signals
	virtual UTbSimpleSimpleArrayInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	TArray<bool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	FString GetPropReadOnlyString_Implementation() const override;

	// operations
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override;
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override;
	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override;
	TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override;

	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override;
	TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override;

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override;
	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override;
	TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override;

	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override;
	TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override;

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override;
	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> PropBool{TArray<bool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<bool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<bool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<int32>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt32{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt32_Private(const TArray<int32>& InPropInt32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int64> PropInt64{TArray<int64>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int64> GetPropInt64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt64_Private(const TArray<int64>& InPropInt64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<float>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat32{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(const TArray<float>& InPropFloat32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<double> PropFloat64{TArray<double>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<double> GetPropFloat64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(const TArray<double>& InPropFloat64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> PropString{TArray<FString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FString>& InPropString);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropReadOnlyString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	FString PropReadOnlyString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	FString GetPropReadOnlyString_Private() const;

private:
	// signals
	UPROPERTY()
	UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals;
};
