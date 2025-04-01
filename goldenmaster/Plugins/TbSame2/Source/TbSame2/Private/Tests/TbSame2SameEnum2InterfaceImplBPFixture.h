
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameEnum2InterfaceImplBPFixture.generated.h"

class UTbSame2SameEnum2InterfaceBPBaseImplSpec;
class ITbSame2SameEnum2InterfaceInterface;

UCLASS()
class UTbSame2SameEnum2InterfaceBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameEnum2InterfaceBPBaseImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame2Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameEnum2InterfaceBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameEnum2InterfaceImplBPFixture
{
public:
	FTbSame2SameEnum2InterfaceImplBPFixture();
	~FTbSame2SameEnum2InterfaceImplBPFixture();

	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame2SameEnum2InterfaceBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame2SameEnum2InterfaceBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
