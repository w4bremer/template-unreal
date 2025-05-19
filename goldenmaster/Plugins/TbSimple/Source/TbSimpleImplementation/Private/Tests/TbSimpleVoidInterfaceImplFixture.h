
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleVoidInterfaceImplFixture.generated.h"

class FTbSimpleVoidInterfaceImplFixture;
class ITbSimpleVoidInterface;

UCLASS()
class UTbSimpleVoidInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSimpleVoidInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SigVoidSignalCb();

protected:
	TWeakPtr<FTbSimpleVoidInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleVoidInterfaceImplFixture
{
public:
	FTbSimpleVoidInterfaceImplFixture();
	~FTbSimpleVoidInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleVoidInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleVoidInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
