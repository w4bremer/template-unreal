

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimpleNoPropertiesInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoPropertiesInterfaceBPBase : public UObject, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoPropertiesInterfaceBPBase();

	// signals
	virtual UTbSimpleNoPropertiesInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	// operations
	void FuncVoid_Implementation() override;

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// properties - local copy

private:
	// signals
	UPROPERTY()
	UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals;
};
