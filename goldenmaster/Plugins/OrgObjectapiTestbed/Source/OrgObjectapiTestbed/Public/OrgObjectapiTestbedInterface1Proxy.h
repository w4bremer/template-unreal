
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "apig/OrgObjectapiTestbed_apig.h"
#include "OrgObjectapiTestbedInterface1Proxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="OrgObjectapiTestbedInterface1")
class ORG_OBJECTAPI_TESTBED_API UOrgObjectapiTestbedInterface1Proxy : public UObject, public IOrgObjectapiTestbedInterface1Interface, public IOrgObjectapiTestbedInterface1SubscriberInterface
{
	GENERATED_BODY()

public:
    explicit UOrgObjectapiTestbedInterface1Proxy();
    virtual ~UOrgObjectapiTestbedInterface1Proxy();

    // signal delegates
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSig1Delegate);
    
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSig2Delegate, int32, Step);
    
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSig3Delegate);
    
    //property delegates
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FbProp1ChangedDelegate, bool, bProp1);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp2ChangedDelegate, int32, Prop2);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp3ChangedDelegate, float, Prop3);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp4ChangedDelegate, FString, Prop4);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp5ChangedDelegate, TArray<int32>, Prop5);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp6ChangedDelegate, const FStruct1&, Prop6);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp7ChangedDelegate, int32, Prop7);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp10ChangedDelegate, TArray<int32>, Prop10);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp11ChangedDelegate, const TArray<FStruct1>&, Prop11);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp12ChangedDelegate, const TArray<EEnum1>&, Prop12);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp14ChangedDelegate, const TArray<FStruct1>&, Prop14);

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FSig1Delegate Sig1Signal;
    void OnSig1();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FSig2Delegate Sig2Signal;
    void OnSig2(int32 Step);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FSig3Delegate Sig3Signal;
    void OnSig3();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FbProp1ChangedDelegate bProp1Changed;
    void OnbProp1Changed(bool Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp2ChangedDelegate Prop2Changed;
    void OnProp2Changed(int32 Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp3ChangedDelegate Prop3Changed;
    void OnProp3Changed(float Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp4ChangedDelegate Prop4Changed;
    void OnProp4Changed(FString Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp5ChangedDelegate Prop5Changed;
    void OnProp5Changed(TArray<int32> Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp6ChangedDelegate Prop6Changed;
    void OnProp6Changed(const FStruct1& Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp7ChangedDelegate Prop7Changed;
    void OnProp7Changed(int32 Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp10ChangedDelegate Prop10Changed;
    void OnProp10Changed(TArray<int32> Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp11ChangedDelegate Prop11Changed;
    void OnProp11Changed(const TArray<FStruct1>& Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp12ChangedDelegate Prop12Changed;
    void OnProp12Changed(const TArray<EEnum1>& Value);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp14ChangedDelegate Prop14Changed;
    void OnProp14Changed(const TArray<FStruct1>& Value);

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    bool GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp1(bool Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp2(int32 Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    float GetProp3() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp3(float Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FString GetProp4() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp4(FString Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp5() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp5(TArray<int32> Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FStruct1 GetProp6() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp6(const FStruct1& Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp7() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp7(int32 Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp10() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp10(TArray<int32> Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> GetProp11() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp11(const TArray<FStruct1>& Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EEnum1> GetProp12() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp12(const TArray<EEnum1>& Value) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> GetProp14() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp14(const TArray<FStruct1>& Value) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void Op1() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void Op2(int32 Step) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Op3(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result);
    int32 Op3() override;

private:
	/** The connection to the service backend. */
	TSharedPtr<IOrgObjectapiTestbedInterface1PublisherInterface, ESPMode::ThreadSafe> service;

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp1, BlueprintSetter=SetProp1, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    bool bProp1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp2, BlueprintSetter=SetProp2, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 Prop2;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp3, BlueprintSetter=SetProp3, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    float Prop3;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp4, BlueprintSetter=SetProp4, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FString Prop4;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp5, BlueprintSetter=SetProp5, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> Prop5;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp6, BlueprintSetter=SetProp6, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FStruct1 Prop6;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp7, BlueprintSetter=SetProp7, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 Prop7;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp10, BlueprintSetter=SetProp10, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> Prop10;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp11, BlueprintSetter=SetProp11, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> Prop11;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp12, BlueprintSetter=SetProp12, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EEnum1> Prop12;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp14, BlueprintSetter=SetProp14, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> Prop14;

};
