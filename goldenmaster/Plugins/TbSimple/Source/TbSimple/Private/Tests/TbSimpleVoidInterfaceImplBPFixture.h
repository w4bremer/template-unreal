
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleVoidInterfaceImplBPFixture.generated.h"

class UTbSimpleVoidInterfaceBPBaseImplSpec;
class ITbSimpleVoidInterfaceInterface;

UCLASS()
class UTbSimpleVoidInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleVoidInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleVoidInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleVoidInterfaceImplBPFixture
{
public:
	FTbSimpleVoidInterfaceImplBPFixture();
	~FTbSimpleVoidInterfaceImplBPFixture();

	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleVoidInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSimpleVoidInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleVoidInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
