
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleEmptyInterfaceImplBPFixture.generated.h"

class UTbSimpleEmptyInterfaceBPBaseImplSpec;
class ITbSimpleEmptyInterfaceInterface;

UCLASS()
class UTbSimpleEmptyInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleEmptyInterfaceBPBaseImplSpec* InSpec);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleEmptyInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleEmptyInterfaceImplBPFixture
{
public:
	FTbSimpleEmptyInterfaceImplBPFixture();
	~FTbSimpleEmptyInterfaceImplBPFixture();

	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleEmptyInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleEmptyInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
