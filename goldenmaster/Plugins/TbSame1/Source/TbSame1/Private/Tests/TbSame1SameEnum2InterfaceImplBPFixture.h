
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum2InterfaceImplBPFixture.generated.h"

class UTbSame1SameEnum2InterfaceBPBaseImplSpec;
class ITbSame1SameEnum2InterfaceInterface;

UCLASS()
class UTbSame1SameEnum2InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameEnum2InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame1Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum2InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum2InterfaceImplBPFixture
{
public:
	FTbSame1SameEnum2InterfaceImplBPFixture();
	~FTbSame1SameEnum2InterfaceImplBPFixture();

	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame1SameEnum2InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame1SameEnum2InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
