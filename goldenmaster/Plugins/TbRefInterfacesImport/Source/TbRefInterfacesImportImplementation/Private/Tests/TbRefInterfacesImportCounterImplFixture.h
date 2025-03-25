
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImportCounterImplFixture.generated.h"

class FTbRefInterfacesImportCounterImplFixture;
class ITbRefInterfacesImportCounter;

UCLASS()
class UTbRefInterfacesImportCounterImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbRefInterfacesImportCounterImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

protected:
	TWeakPtr<FTbRefInterfacesImportCounterImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbRefInterfacesImportCounterImplFixture
{
public:
	FTbRefInterfacesImportCounterImplFixture();
	~FTbRefInterfacesImportCounterImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesImportCounter> GetImplementation();
	TSoftObjectPtr<UTbRefInterfacesImportCounterImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesImportCounter> testImplementation;
	TSoftObjectPtr<UTbRefInterfacesImportCounterImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
