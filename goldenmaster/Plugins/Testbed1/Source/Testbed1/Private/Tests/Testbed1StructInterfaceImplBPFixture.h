
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "Testbed1StructInterfaceImplBPFixture.generated.h"

class UTestbed1StructInterfaceBPBaseImplSpec;
class ITestbed1StructInterfaceInterface;

UCLASS()
class UTestbed1StructInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBool& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructInt& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructString& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructInt& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructString& ParamString);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructInterfaceImplBPFixture
{
public:
	FTestbed1StructInterfaceImplBPFixture();
	~FTestbed1StructInterfaceImplBPFixture();

	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed1StructInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed1StructInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
