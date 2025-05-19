
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceImplFixture.generated.h"

class FTbSimpleNoPropertiesInterfaceImplFixture;
class ITbSimpleNoPropertiesInterface;

UCLASS()
class UTbSimpleNoPropertiesInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSimpleNoPropertiesInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	TWeakPtr<FTbSimpleNoPropertiesInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoPropertiesInterfaceImplFixture
{
public:
	FTbSimpleNoPropertiesInterfaceImplFixture();
	~FTbSimpleNoPropertiesInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
