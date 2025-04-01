

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/CounterCounterInterface.h"
#include "CounterCounterBPBase.generated.h"

UCLASS(BlueprintType)
class COUNTER_API UCounterCounterBPBase : public UObject, public ICounterCounterInterface
{
	GENERATED_BODY()
public:
	virtual ~UCounterCounterBPBase();

	// signals
	virtual UCounterCounterSignals* _GetSignals_Implementation() override;

	// properties
	FCustomTypesVector3D GetVector_Implementation() const override;
	void SetVector_Implementation(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector_Implementation() const override;
	void SetExternVector_Implementation(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override;
	void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray_Implementation() const override;
	void SetExternVectorArray_Implementation(const TArray<FVector>& ExternVectorArray) override;

	// operations
	virtual void IncrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec) override;
	FVector Increment_Implementation(const FVector& Vec) override;

	virtual void IncrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec) override;
	TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override;

	virtual void DecrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec) override;
	FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override;

	virtual void DecrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec) override;
	TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override;

protected:
	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetVector_Private, BlueprintSetter = SetVector_Private, Category = "ApiGear|Counter|Counter")
	FCustomTypesVector3D Vector{FCustomTypesVector3D()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	FCustomTypesVector3D GetVector_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetVector_Private(const FCustomTypesVector3D& InVector);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetExternVector_Private, BlueprintSetter = SetExternVector_Private, Category = "ApiGear|Counter|Counter")
	FVector ExternVector{FVector(0.f, 0.f, 0.f)};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	FVector GetExternVector_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetExternVector_Private(const FVector& InExternVector);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetVectorArray_Private, BlueprintSetter = SetVectorArray_Private, Category = "ApiGear|Counter|Counter")
	TArray<FCustomTypesVector3D> VectorArray{TArray<FCustomTypesVector3D>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	TArray<FCustomTypesVector3D> GetVectorArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetVectorArray_Private(const TArray<FCustomTypesVector3D>& InVectorArray);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetExternVectorArray_Private, BlueprintSetter = SetExternVectorArray_Private, Category = "ApiGear|Counter|Counter")
	TArray<FVector> ExternVectorArray{TArray<FVector>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	TArray<FVector> GetExternVectorArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetExternVectorArray_Private(const TArray<FVector>& InExternVectorArray);

private:
	// signals
	UPROPERTY()
	UCounterCounterSignals* CounterCounterSignals;
};
