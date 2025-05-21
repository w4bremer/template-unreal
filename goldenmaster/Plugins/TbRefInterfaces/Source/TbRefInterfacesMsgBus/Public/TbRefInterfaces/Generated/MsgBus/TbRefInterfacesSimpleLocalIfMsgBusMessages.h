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

#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesSimpleLocalIfMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbRefInterfacesSimpleLocalIfDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbRefInterfacesSimpleLocalIfDiscoveryMessageType Type = ETbRefInterfacesSimpleLocalIfDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfIntSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param = 0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfSetIntPropertyRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfIntPropertyChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfIntMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Param = 0;
};

USTRUCT()
struct FTbRefInterfacesSimpleLocalIfIntMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Result = 0;
};
