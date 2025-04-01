
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoSignalsInterfaceImplBPFixture.generated.h"

class UTbSimpleNoSignalsInterfaceBPBaseImplSpec;
class ITbSimpleNoSignalsInterfaceInterface;

UCLASS()
class UTbSimpleNoSignalsInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoSignalsInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoSignalsInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoSignalsInterfaceImplBPFixture
{
public:
	FTbSimpleNoSignalsInterfaceImplBPFixture();
	~FTbSimpleNoSignalsInterfaceImplBPFixture();

	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleNoSignalsInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleNoSignalsInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
