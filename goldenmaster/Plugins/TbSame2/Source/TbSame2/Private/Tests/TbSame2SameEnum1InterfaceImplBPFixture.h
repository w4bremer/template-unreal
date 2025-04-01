
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameEnum1InterfaceImplBPFixture.generated.h"

class UTbSame2SameEnum1InterfaceBPBaseImplSpec;
class ITbSame2SameEnum1InterfaceInterface;

UCLASS()
class UTbSame2SameEnum1InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameEnum1InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameEnum1InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameEnum1InterfaceImplBPFixture
{
public:
	FTbSame2SameEnum1InterfaceImplBPFixture();
	~FTbSame2SameEnum1InterfaceImplBPFixture();

	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame2SameEnum1InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame2SameEnum1InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
