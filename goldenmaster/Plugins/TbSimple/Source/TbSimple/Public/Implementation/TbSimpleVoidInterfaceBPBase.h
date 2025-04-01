

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "TbSimpleVoidInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleVoidInterfaceBPBase : public UObject, public ITbSimpleVoidInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleVoidInterfaceBPBase();

	// signals
	virtual UTbSimpleVoidInterfaceSignals* _GetSignals_Implementation() override;

	// properties
	// operations
	void FuncVoid_Implementation() override;

protected:
	// properties - local copy

private:
	// signals
	UPROPERTY()
	UTbSimpleVoidInterfaceSignals* TbSimpleVoidInterfaceSignals;
};
