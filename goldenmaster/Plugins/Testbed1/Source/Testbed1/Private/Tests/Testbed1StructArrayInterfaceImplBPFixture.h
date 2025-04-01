
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "Testbed1StructArrayInterfaceImplBPFixture.generated.h"

class UTestbed1StructArrayInterfaceBPBaseImplSpec;
class ITestbed1StructArrayInterfaceInterface;

UCLASS()
class UTestbed1StructArrayInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructArrayInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArrayInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArrayInterfaceImplBPFixture
{
public:
	FTestbed1StructArrayInterfaceImplBPFixture();
	~FTestbed1StructArrayInterfaceImplBPFixture();

	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed1StructArrayInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITestbed1StructArrayInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed1StructArrayInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
