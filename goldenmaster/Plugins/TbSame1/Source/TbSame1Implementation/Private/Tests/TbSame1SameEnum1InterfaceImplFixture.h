
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceImplFixture.generated.h"

class FTbSame1SameEnum1InterfaceImplFixture;
class ITbSame1SameEnum1Interface;

UCLASS()
class UTbSame1SameEnum1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame1SameEnum1InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

protected:
	TWeakPtr<FTbSame1SameEnum1InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum1InterfaceImplFixture
{
public:
	FTbSame1SameEnum1InterfaceImplFixture();
	~FTbSame1SameEnum1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum1Interface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1Interface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
