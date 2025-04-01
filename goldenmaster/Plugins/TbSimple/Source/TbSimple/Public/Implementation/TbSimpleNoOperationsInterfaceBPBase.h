

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimpleNoOperationsInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoOperationsInterfaceBPBase : public UObject, public ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoOperationsInterfaceBPBase();

	// signals
	virtual UTbSimpleNoOperationsInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	// operations

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

private:
	// signals
	UPROPERTY()
	UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals;
};
