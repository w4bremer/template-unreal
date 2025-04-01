

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "TbSimpleEmptyInterfaceBPBase.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleEmptyInterfaceBPBase : public UObject, public ITbSimpleEmptyInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleEmptyInterfaceBPBase();

	// properties
	// operations

protected:
	// properties - local copy

private:
};
