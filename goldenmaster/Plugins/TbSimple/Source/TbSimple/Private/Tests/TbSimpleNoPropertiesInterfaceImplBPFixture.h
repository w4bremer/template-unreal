
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceImplBPFixture.generated.h"

class UTbSimpleNoPropertiesInterfaceBPBaseImplSpec;
class ITbSimpleNoPropertiesInterfaceInterface;

UCLASS()
class UTbSimpleNoPropertiesInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoPropertiesInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoPropertiesInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoPropertiesInterfaceImplBPFixture
{
public:
	FTbSimpleNoPropertiesInterfaceImplBPFixture();
	~FTbSimpleNoPropertiesInterfaceImplBPFixture();

	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleNoPropertiesInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleNoPropertiesInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
