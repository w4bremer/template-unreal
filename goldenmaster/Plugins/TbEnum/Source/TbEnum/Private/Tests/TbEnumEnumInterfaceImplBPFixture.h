
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbEnum_data.h"
#include "TbEnumEnumInterfaceImplBPFixture.generated.h"

class UTbEnumEnumInterfaceBPBaseImplSpec;
class ITbEnumEnumInterfaceInterface;

UCLASS()
class UTbEnumEnumInterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbEnumEnumInterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop0PropertyCb(ETbEnumEnum0 Prop0);

	UFUNCTION()
	void Prop1PropertyCb(ETbEnumEnum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbEnumEnum2 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(ETbEnumEnum3 Prop3);

	UFUNCTION()
	void Sig0SignalCb(ETbEnumEnum0 Param0);

	UFUNCTION()
	void Sig1SignalCb(ETbEnumEnum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbEnumEnum2 Param2);

	UFUNCTION()
	void Sig3SignalCb(ETbEnumEnum3 Param3);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbEnumEnumInterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbEnumEnumInterfaceImplBPFixture
{
public:
	FTbEnumEnumInterfaceImplBPFixture();
	~FTbEnumEnumInterfaceImplBPFixture();

	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbEnumEnumInterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbEnumEnumInterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
