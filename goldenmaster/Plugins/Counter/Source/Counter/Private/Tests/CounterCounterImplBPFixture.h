
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Counter_data.h"
#include "CounterCounterImplBPFixture.generated.h"

class UCounterCounterBPBaseImplSpec;
class ICounterCounterInterface;

UCLASS()
class UCounterCounterBPBaseImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UCounterCounterBPBaseImplSpec* InSpec);

	UFUNCTION()
	void VectorPropertyCb(const FCustomTypesVector3D& Vector);

	UFUNCTION()
	void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION()
	void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

protected:
	const FDoneDelegate* testDoneDelegate;
	UCounterCounterBPBaseImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FCounterCounterImplBPFixture
{
public:
	FCounterCounterImplBPFixture();
	~FCounterCounterImplBPFixture();

	TScriptInterface<ICounterCounterInterface> GetImplementation();
	TWeakObjectPtr<UCounterCounterBPBaseImplHelper> GetHelper();

private:
	void CleanUp();

	TScriptInterface<ICounterCounterInterface> testImplementation;
	TWeakObjectPtr<UCounterCounterBPBaseImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
