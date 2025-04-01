
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameStruct1InterfaceImplBPFixture.generated.h"

class UTbSame2SameStruct1InterfaceBPBaseImplSpec;
class ITbSame2SameStruct1InterfaceInterface;

UCLASS()
class UTbSame2SameStruct1InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameStruct1InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameStruct1InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameStruct1InterfaceImplBPFixture
{
public:
	FTbSame2SameStruct1InterfaceImplBPFixture();
	~FTbSame2SameStruct1InterfaceImplBPFixture();

	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame2SameStruct1InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame2SameStruct1InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
