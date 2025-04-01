
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "TbNamesNamEsImplBPFixture.generated.h"

class UTbNamesNamEsBPBaseImplSpec;
class ITbNamesNamEsInterface;

UCLASS()
class UTbNamesNamEsBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbNamesNamEsBPBaseImplSpec* InSpec);

	UFUNCTION()
	void SwitchPropertyCb(bool bSwitch);

	UFUNCTION()
	void SomePropertyPropertyCb(int32 SomeProperty);

	UFUNCTION()
	void SomePoperty2PropertyCb(int32 SomePoperty2);

	UFUNCTION()
	void SomeSignalSignalCb(bool bSomeParam);

	UFUNCTION()
	void SomeSignal2SignalCb(bool bSomeParam);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbNamesNamEsBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbNamesNamEsImplBPFixture
{
public:
	FTbNamesNamEsImplBPFixture();
	~FTbNamesNamEsImplBPFixture();

	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	TWeakObjectPtr<UTbNamesNamEsBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
	TWeakObjectPtr<UTbNamesNamEsBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
