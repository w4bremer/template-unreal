

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/TbNamesNamEsInterface.h"
#include "TbNamesNamEsBPBase.generated.h"

UCLASS(BlueprintType)
class TBNAMES_API UTbNamesNamEsBPBase : public UObject, public ITbNamesNamEsInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbNamesNamEsBPBase();

	// signals
	virtual UTbNamesNamEsSignals* _GetSignals_Implementation() override;

	// properties
	bool GetSwitch_Implementation() const override;
	void SetSwitch_Implementation(bool bSwitch) override;

	int32 GetSomeProperty_Implementation() const override;
	void SetSomeProperty_Implementation(int32 SomeProperty) override;

	int32 GetSomePoperty2_Implementation() const override;
	void SetSomePoperty2_Implementation(int32 SomePoperty2) override;

	// operations
	void SomeFunction_Implementation(bool bSomeParam) override;

	void SomeFunction2_Implementation(bool bSomeParam) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetSwitch_Private, BlueprintSetter = SetSwitch_Private, Category = "ApiGear|TbNames|NamEs")
	bool bSwitch{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	bool GetSwitch_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSwitch_Private(bool bInSwitch);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetSomeProperty_Private, BlueprintSetter = SetSomeProperty_Private, Category = "ApiGear|TbNames|NamEs")
	int32 SomeProperty{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	int32 GetSomeProperty_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSomeProperty_Private(int32 InSomeProperty);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetSomePoperty2_Private, BlueprintSetter = SetSomePoperty2_Private, Category = "ApiGear|TbNames|NamEs")
	int32 SomePoperty2{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	int32 GetSomePoperty2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSomePoperty2_Private(int32 InSomePoperty2);

private:
	// signals
	UPROPERTY()
	UTbNamesNamEsSignals* TbNamesNamEsSignals;
};
