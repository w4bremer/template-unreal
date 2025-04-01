
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceImplBPFixture.generated.h"

class UTbSame1SameEnum1InterfaceBPBaseImplSpec;
class ITbSame1SameEnum1InterfaceInterface;

UCLASS()
class UTbSame1SameEnum1InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameEnum1InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum1InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum1InterfaceImplBPFixture
{
public:
	FTbSame1SameEnum1InterfaceImplBPFixture();
	~FTbSame1SameEnum1InterfaceImplBPFixture();

	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame1SameEnum1InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame1SameEnum1InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
