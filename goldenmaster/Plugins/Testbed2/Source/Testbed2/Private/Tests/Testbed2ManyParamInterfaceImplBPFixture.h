
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2ManyParamInterfaceImplBPFixture.generated.h"

class UTestbed2ManyParamInterfaceBPBaseImplSpec;
class ITestbed2ManyParamInterfaceInterface;

UCLASS()
class UTestbed2ManyParamInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2ManyParamInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(int32 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(int32 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(int32 Prop3);

	UFUNCTION()
	void Prop4PropertyCb(int32 Prop4);

	UFUNCTION()
	void Sig1SignalCb(int32 Param1);

	UFUNCTION()
	void Sig2SignalCb(int32 Param1, int32 Param2);

	UFUNCTION()
	void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION()
	void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2ManyParamInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2ManyParamInterfaceImplBPFixture
{
public:
	FTestbed2ManyParamInterfaceImplBPFixture();
	~FTestbed2ManyParamInterfaceImplBPFixture();

	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2ManyParamInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITestbed2ManyParamInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2ManyParamInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
