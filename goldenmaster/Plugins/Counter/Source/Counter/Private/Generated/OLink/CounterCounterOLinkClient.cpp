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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Generated/OLink/CounterCounterOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "Counter/Generated/api/Counter.json.adapter.h"
#include "CustomTypes/Generated/api/CustomTypes.json.adapter.h"
#include "ExternTypes/Generated/api/ExternTypes.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "CounterSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct CounterCounterPropertiesData
{
	FCriticalSection VectorMutex;
	FCustomTypesVector3D Vector{FCustomTypesVector3D()};
	FCriticalSection ExternVectorMutex;
	FVector ExternVector{FVector(0.f, 0.f, 0.f)};
	FCriticalSection VectorArrayMutex;
	TArray<FCustomTypesVector3D> VectorArray{TArray<FCustomTypesVector3D>()};
	FCriticalSection ExternVectorArrayMutex;
	TArray<FVector> ExternVectorArray{TArray<FVector>()};
};
DEFINE_LOG_CATEGORY(LogCounterCounterOLinkClient);

UCounterCounterOLinkClient::UCounterCounterOLinkClient()
	: UAbstractCounterCounter()
	, _SentData(MakePimpl<CounterCounterPropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("counter.Counter");
}

UCounterCounterOLinkClient::UCounterCounterOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UCounterCounterOLinkClient::~UCounterCounterOLinkClient() = default;

void UCounterCounterOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(true);
	});
	m_sink->setOnReleaseCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(false);
	});

	FOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);

	check(GEngine);
	UCounterSettings* settings = GetMutableDefault<UCounterSettings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("No valid olink connection for the %s client, please set in the ApiGear Counter plugin settings or during run time"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UCounterCounterOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();
	m_sink->resetOnInitCallback();
	m_sink->resetOnReleaseCallback();

	if (Connection.GetObject())
	{
		UOLinkClientConnection* UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UCounterCounterOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearOLinkProtocolIdentifier, TEXT("Cannot use connection - must be of type olink"));

	UOLinkClientConnection* UnrealOLinkConnection = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
		UnrealOLinkConnection = nullptr;
	}

	// set up new connection
	UnrealOLinkConnection = Cast<UOLinkClientConnection>(InConnection.GetObject());
	UnrealOLinkConnection->node()->registry().addSink(m_sink);
	UnrealOLinkConnection->linkObjectSource(m_sink->olinkObjectName());

	Connection = InConnection;
}

FCustomTypesVector3D UCounterCounterOLinkClient::GetVector_Implementation() const
{
	return Vector;
}

void UCounterCounterOLinkClient::SetVector_Implementation(const FCustomTypesVector3D& InVector)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetVector_Implementation() == InVector)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->VectorMutex));
		if (_SentData->Vector == InVector)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "vector");
	m_sink->GetNode()->setRemoteProperty(memberId, InVector);
	FScopeLock Lock(&(_SentData->VectorMutex));
	_SentData->Vector = InVector;
}

FVector UCounterCounterOLinkClient::GetExternVector_Implementation() const
{
	return ExternVector;
}

void UCounterCounterOLinkClient::SetExternVector_Implementation(const FVector& InExternVector)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetExternVector_Implementation() == InExternVector)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->ExternVectorMutex));
		if (_SentData->ExternVector == InExternVector)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "extern_vector");
	m_sink->GetNode()->setRemoteProperty(memberId, InExternVector);
	FScopeLock Lock(&(_SentData->ExternVectorMutex));
	_SentData->ExternVector = InExternVector;
}

TArray<FCustomTypesVector3D> UCounterCounterOLinkClient::GetVectorArray_Implementation() const
{
	return VectorArray;
}

void UCounterCounterOLinkClient::SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetVectorArray_Implementation() == InVectorArray)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->VectorArrayMutex));
		if (_SentData->VectorArray == InVectorArray)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "vectorArray");
	m_sink->GetNode()->setRemoteProperty(memberId, InVectorArray);
	FScopeLock Lock(&(_SentData->VectorArrayMutex));
	_SentData->VectorArray = InVectorArray;
}

TArray<FVector> UCounterCounterOLinkClient::GetExternVectorArray_Implementation() const
{
	return ExternVectorArray;
}

void UCounterCounterOLinkClient::SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetExternVectorArray_Implementation() == InExternVectorArray)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->ExternVectorArrayMutex));
		if (_SentData->ExternVectorArray == InExternVectorArray)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "extern_vectorArray");
	m_sink->GetNode()->setRemoteProperty(memberId, InExternVectorArray);
	FScopeLock Lock(&(_SentData->ExternVectorArrayMutex));
	_SentData->ExternVectorArray = InExternVectorArray;
}

FVector UCounterCounterOLinkClient::Increment_Implementation(const FVector& Vec)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FVector(0.f, 0.f, 0.f);
	}
	TPromise<FVector> Promise;
	Async(EAsyncExecution::ThreadPool,
		[Vec, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetCounterStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			if (!arg.value.empty())
			{
				Promise.SetValue(arg.value.get<FVector>());
			}
			else
			{
				UE_LOG(LogCounterCounterOLinkClient, Error, TEXT("Increment: OLink service returned empty value - should have returned type of FVector"));
				Promise.SetValue(FVector());
			}
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "increment");
		m_sink->GetNode()->invokeRemote(memberId, {Vec}, GetCounterStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FVector> UCounterCounterOLinkClient::IncrementArray_Implementation(const TArray<FVector>& Vec)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FVector>();
	}
	TPromise<TArray<FVector>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[Vec, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetCounterStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FVector>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "incrementArray");
		m_sink->GetNode()->invokeRemote(memberId, {Vec}, GetCounterStateFunc);
	});

	return Promise.GetFuture().Get();
}

FCustomTypesVector3D UCounterCounterOLinkClient::Decrement_Implementation(const FCustomTypesVector3D& Vec)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return FCustomTypesVector3D();
	}
	TPromise<FCustomTypesVector3D> Promise;
	Async(EAsyncExecution::ThreadPool,
		[Vec, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetCounterStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			if (!arg.value.empty())
			{
				Promise.SetValue(arg.value.get<FCustomTypesVector3D>());
			}
			else
			{
				UE_LOG(LogCounterCounterOLinkClient, Error, TEXT("Decrement: OLink service returned empty value - should have returned type of FCustomTypesVector3D"));
				Promise.SetValue(FCustomTypesVector3D());
			}
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "decrement");
		m_sink->GetNode()->invokeRemote(memberId, {Vec}, GetCounterStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FCustomTypesVector3D> UCounterCounterOLinkClient::DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogCounterCounterOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FCustomTypesVector3D>();
	}
	TPromise<TArray<FCustomTypesVector3D>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[Vec, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetCounterStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FCustomTypesVector3D>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "decrementArray");
		m_sink->GetNode()->invokeRemote(memberId, {Vec}, GetCounterStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UCounterCounterOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UCounterCounterOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bVectorChanged = fields.contains("vector") && (Vector != fields["vector"].get<FCustomTypesVector3D>());
	if (bVectorChanged)
	{
		Vector = fields["vector"].get<FCustomTypesVector3D>();
		Execute__GetSignals(this)->OnVectorChanged.Broadcast(Vector);
	}

	const bool bExternVectorChanged = fields.contains("extern_vector") && (ExternVector != fields["extern_vector"].get<FVector>());
	if (bExternVectorChanged)
	{
		ExternVector = fields["extern_vector"].get<FVector>();
		Execute__GetSignals(this)->OnExternVectorChanged.Broadcast(ExternVector);
	}

	const bool bVectorArrayChanged = fields.contains("vectorArray") && (VectorArray != fields["vectorArray"].get<TArray<FCustomTypesVector3D>>());
	if (bVectorArrayChanged)
	{
		VectorArray = fields["vectorArray"].get<TArray<FCustomTypesVector3D>>();
		Execute__GetSignals(this)->OnVectorArrayChanged.Broadcast(VectorArray);
	}

	const bool bExternVectorArrayChanged = fields.contains("extern_vectorArray") && (ExternVectorArray != fields["extern_vectorArray"].get<TArray<FVector>>());
	if (bExternVectorArrayChanged)
	{
		ExternVectorArray = fields["extern_vectorArray"].get<TArray<FVector>>();
		Execute__GetSignals(this)->OnExternVectorArrayChanged.Broadcast(ExternVectorArray);
	}
}

void UCounterCounterOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "valueChanged")
	{
		const FCustomTypesVector3D& outVector = args[0].get<FCustomTypesVector3D>();
		const FVector& outExternVector = args[1].get<FVector>();
		const TArray<FCustomTypesVector3D>& outVectorArray = args[2].get<TArray<FCustomTypesVector3D>>();
		const TArray<FVector>& outExternVectorArray = args[3].get<TArray<FVector>>();
		Execute__GetSignals(this)->OnValueChangedSignal.Broadcast(outVector, outExternVector, outVectorArray, outExternVectorArray);
		return;
	}
}
