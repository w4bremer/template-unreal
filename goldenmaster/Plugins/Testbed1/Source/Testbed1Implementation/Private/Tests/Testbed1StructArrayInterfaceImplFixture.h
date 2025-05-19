
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructArrayInterfaceImplFixture.generated.h"

class FTestbed1StructArrayInterfaceImplFixture;
class ITestbed1StructArrayInterface;

UCLASS()
class UTestbed1StructArrayInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed1StructArrayInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const TArray<ETestbed1Enum0>& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);

	UFUNCTION()
	void SigEnumSignalCb(const TArray<ETestbed1Enum0>& ParamEnum);

protected:
	TWeakPtr<FTestbed1StructArrayInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArrayInterfaceImplFixture
{
public:
	FTestbed1StructArrayInterfaceImplFixture();
	~FTestbed1StructArrayInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArrayInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArrayInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArrayInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
