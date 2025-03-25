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
#include "TbRefInterfacesParentIfMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbRefInterfacesParentIfDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbRefInterfacesParentIfDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbRefInterfacesParentIfDiscoveryMessageType Type = ETbRefInterfacesParentIfDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbRefInterfacesParentIfServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesParentIfInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIf = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIf = TScriptInterface<ITbRefInterfacesImportCounter>();
};

USTRUCT()
struct FTbRefInterfacesParentIfClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesParentIfServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefInterfacesParentIfPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefInterfacesParentIfPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefInterfacesParentIfLocalIfSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> Param = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
};

USTRUCT()
struct FTbRefInterfacesParentIfImportedIfSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> Param = TScriptInterface<ITbRefInterfacesImportCounter>();
};

USTRUCT()
struct FTbRefInterfacesParentIfSetLocalIfRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIf = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
};

USTRUCT()
struct FTbRefInterfacesParentIfLocalIfChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> LocalIf = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
};

USTRUCT()
struct FTbRefInterfacesParentIfSetImportedIfRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIf = TScriptInterface<ITbRefInterfacesImportCounter>();
};

USTRUCT()
struct FTbRefInterfacesParentIfImportedIfChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> ImportedIf = TScriptInterface<ITbRefInterfacesImportCounter>();
};

USTRUCT()
struct FTbRefInterfacesParentIfLocalIfMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> Param = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
};

USTRUCT()
struct FTbRefInterfacesParentIfLocalIfMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> Result = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
};

USTRUCT()
struct FTbRefInterfacesParentIfImportedIfMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> Param = TScriptInterface<ITbRefInterfacesImportCounter>();
};

USTRUCT()
struct FTbRefInterfacesParentIfImportedIfMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefInterfacesImportCounter> Result = TScriptInterface<ITbRefInterfacesImportCounter>();
};
