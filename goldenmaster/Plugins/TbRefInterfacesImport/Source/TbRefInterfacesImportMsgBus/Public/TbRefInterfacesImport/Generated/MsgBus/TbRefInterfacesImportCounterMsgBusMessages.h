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

#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImportCounterMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbRefInterfacesImportCounterDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbRefInterfacesImportCounterDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbRefInterfacesImportCounterDiscoveryMessageType Type = ETbRefInterfacesImportCounterDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbRefInterfacesImportCounterServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesImportCounterInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;
};

USTRUCT()
struct FTbRefInterfacesImportCounterClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesImportCounterServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesImportCounterPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefInterfacesImportCounterPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};
