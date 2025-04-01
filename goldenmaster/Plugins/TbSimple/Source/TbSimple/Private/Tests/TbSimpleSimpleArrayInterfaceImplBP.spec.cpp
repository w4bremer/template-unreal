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

#include "TbSimpleSimpleArrayInterfaceImplBP.spec.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterfaceImplBPFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplBPFixture = MakeUnique<FTbSimpleSimpleArrayInterfaceImplBPFixture>();
		TestTrue("Check for valid ImplBPFixture", ImplBPFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplBPFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplBPFixture->GetHelper().IsValid());
		ImplBPFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplBPFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue.Add(true);
		ImplBPFixture->GetImplementation()->Execute_SetPropBool(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplBPFixture->GetImplementation()->Execute_SetPropInt(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt32(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt32(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt32PropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplBPFixture->GetImplementation()->Execute_SetPropInt32(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt64(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropInt64(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropInt64PropertyCb);
		// use different test value
		TestValue.Add(1LL);
		ImplBPFixture->GetImplementation()->Execute_SetPropInt64(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplBPFixture->GetImplementation()->Execute_SetPropFloat(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat32(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat32(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat32PropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplBPFixture->GetImplementation()->Execute_SetPropFloat32(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat64(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat64(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropFloat64PropertyCb);
		// use different test value
		TestValue.Add(1.0);
		ImplBPFixture->GetImplementation()->Execute_SetPropFloat64(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropString(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropString(ImplBPFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		ImplBPFixture->GetImplementation()->Execute_SetPropString(ImplBPFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropReadOnlyString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplBPFixture->GetImplementation()->Execute_GetPropReadOnlyString(ImplBPFixture->GetImplementation().GetObject()), FString());
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncBool(ImplBPFixture->GetImplementation().GetObject(), TArray<bool>());
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncInt(ImplBPFixture->GetImplementation().GetObject(), TArray<int32>());
	});

	It("Operation.FuncInt32", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncInt32(ImplBPFixture->GetImplementation().GetObject(), TArray<int32>());
	});

	It("Operation.FuncInt64", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncInt64(ImplBPFixture->GetImplementation().GetObject(), TArray<int64>());
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncFloat(ImplBPFixture->GetImplementation().GetObject(), TArray<float>());
	});

	It("Operation.FuncFloat32", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncFloat32(ImplBPFixture->GetImplementation().GetObject(), TArray<float>());
	});

	It("Operation.FuncFloat64", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncFloat64(ImplBPFixture->GetImplementation().GetObject(), TArray<double>());
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplBPFixture->GetImplementation()->Execute_FuncString(ImplBPFixture->GetImplementation().GetObject(), TArray<FString>());
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigBoolSignalCb);

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigIntSignalCb);

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt32SignalCb);

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigInt64SignalCb);

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloatSignalCb);

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat32SignalCb);

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64Signal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigFloat64SignalCb);

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplBPFixture->GetImplementation()->Execute__GetSignals(ImplBPFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignal.AddDynamic(ImplBPFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceBPBaseImplHelper::SigStringSignalCb);

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropBool(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropInt(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropInt32(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropInt64(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat32(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropFloat64(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplBPFixture->GetImplementation()->Execute_GetPropString(ImplBPFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceBPBaseImplSpec::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
