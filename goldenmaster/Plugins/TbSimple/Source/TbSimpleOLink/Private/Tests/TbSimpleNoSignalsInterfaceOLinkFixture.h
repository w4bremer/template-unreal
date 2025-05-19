
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class FTbSimpleNoSignalsInterfaceOLinkFixture;
class ITbSimpleNoSignalsInterface;
class UTbSimpleNoSignalsInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace OLink
{
namespace Tests
{
class FTbSimpleNoSignalsInterfaceOLinkFixture
{
public:
	FTbSimpleNoSignalsInterfaceOLinkFixture();
	~FTbSimpleNoSignalsInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleNoSignalsInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NoSignalsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
