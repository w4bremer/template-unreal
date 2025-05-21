
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"
#include "TbRefInterfacesSimpleLocalIfImplFixture.generated.h"

class FTbRefInterfacesSimpleLocalIfImplFixture;
class ITbRefInterfacesSimpleLocalIf;

UCLASS()
class UTbRefInterfacesSimpleLocalIfImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbRefInterfacesSimpleLocalIfImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void IntPropertyPropertyCb(int32 IntProperty);

	UFUNCTION()
	void IntSignalSignalCb(int32 Param);

protected:
	TWeakPtr<FTbRefInterfacesSimpleLocalIfImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbRefInterfacesSimpleLocalIfImplFixture
{
public:
	FTbRefInterfacesSimpleLocalIfImplFixture();
	~FTbRefInterfacesSimpleLocalIfImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetImplementation();
	TSoftObjectPtr<UTbRefInterfacesSimpleLocalIfImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> testImplementation;
	TSoftObjectPtr<UTbRefInterfacesSimpleLocalIfImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
