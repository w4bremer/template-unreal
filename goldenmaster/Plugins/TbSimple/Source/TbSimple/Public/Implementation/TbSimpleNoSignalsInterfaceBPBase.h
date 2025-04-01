

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "TbSimpleNoSignalsInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoSignalsInterfaceBPBase : public UObject, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoSignalsInterfaceBPBase();

	// signals
	virtual UTbSimpleNoSignalsInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	// operations
	void FuncVoid_Implementation() override;

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

private:
	// signals
	UPROPERTY()
	UTbSimpleNoSignalsInterfaceSignals* TbSimpleNoSignalsInterfaceSignals;
};
