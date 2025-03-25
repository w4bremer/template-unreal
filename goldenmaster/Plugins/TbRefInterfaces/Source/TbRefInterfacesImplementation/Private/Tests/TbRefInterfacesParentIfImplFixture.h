
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"
#include "TbRefInterfacesParentIfImplFixture.generated.h"

class FTbRefInterfacesParentIfImplFixture;
class ITbRefInterfacesParentIf;

UCLASS()
class UTbRefInterfacesParentIfImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbRefInterfacesParentIfImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void LocalIfPropertyCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& LocalIf);

	UFUNCTION()
	void ImportedIfPropertyCb(const TScriptInterface<ITbRefInterfacesImportCounter>& ImportedIf);

	UFUNCTION()
	void LocalIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);

	UFUNCTION()
	void ImportedIfSignalSignalCb(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);

protected:
	TWeakPtr<FTbRefInterfacesParentIfImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbRefInterfacesParentIfImplFixture
{
public:
	FTbRefInterfacesParentIfImplFixture();
	~FTbRefInterfacesParentIfImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesParentIf> GetImplementation();
	TSoftObjectPtr<UTbRefInterfacesParentIfImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesParentIf> testImplementation;
	TSoftObjectPtr<UTbRefInterfacesParentIfImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
