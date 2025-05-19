
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct2InterfaceImplFixture.generated.h"

class FTestbed2NestedStruct2InterfaceImplFixture;
class ITestbed2NestedStruct2Interface;

UCLASS()
class UTestbed2NestedStruct2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed2NestedStruct2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

protected:
	TWeakPtr<FTestbed2NestedStruct2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct2InterfaceImplFixture
{
public:
	FTestbed2NestedStruct2InterfaceImplFixture();
	~FTestbed2NestedStruct2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2Interface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2Interface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
