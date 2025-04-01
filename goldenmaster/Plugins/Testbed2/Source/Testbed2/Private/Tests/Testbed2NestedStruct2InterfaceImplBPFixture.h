
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct2InterfaceImplBPFixture.generated.h"

class UTestbed2NestedStruct2InterfaceBPBaseImplSpec;
class ITestbed2NestedStruct2InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct2InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct2InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct2InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct2InterfaceImplBPFixture
{
public:
	FTestbed2NestedStruct2InterfaceImplBPFixture();
	~FTestbed2NestedStruct2InterfaceImplBPFixture();

	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2NestedStruct2InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2NestedStruct2InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
