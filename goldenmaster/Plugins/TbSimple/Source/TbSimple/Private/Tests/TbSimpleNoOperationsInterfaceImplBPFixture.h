
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceImplBPFixture.generated.h"

class UTbSimpleNoOperationsInterfaceBPBaseImplSpec;
class ITbSimpleNoOperationsInterfaceInterface;

UCLASS()
class UTbSimpleNoOperationsInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoOperationsInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoOperationsInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoOperationsInterfaceImplBPFixture
{
public:
	FTbSimpleNoOperationsInterfaceImplBPFixture();
	~FTbSimpleNoOperationsInterfaceImplBPFixture();

	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleNoOperationsInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleNoOperationsInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
