
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"

class FTbNamesNamEsOLinkFixture;
class ITbNamesNamEs;
class UTbNamesNamEsOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace OLink
{
namespace Tests
{
class FTbNamesNamEsOLinkFixture
{
public:
	FTbNamesNamEsOLinkFixture();
	~FTbNamesNamEsOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEs> GetImplementation();
	UOLinkHost* GetHost();
	UTbNamesNamEsOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEs> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
