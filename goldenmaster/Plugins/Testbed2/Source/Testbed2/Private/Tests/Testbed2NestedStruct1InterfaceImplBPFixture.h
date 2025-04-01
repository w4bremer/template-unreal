
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct1InterfaceImplBPFixture.generated.h"

class UTestbed2NestedStruct1InterfaceBPBaseImplSpec;
class ITestbed2NestedStruct1InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct1InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct1InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct1InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct1InterfaceImplBPFixture
{
public:
	FTestbed2NestedStruct1InterfaceImplBPFixture();
	~FTestbed2NestedStruct1InterfaceImplBPFixture();

	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2NestedStruct1InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2NestedStruct1InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
