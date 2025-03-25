
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"

class FTbRefInterfacesSimpleLocalIfOLinkFixture;
class ITbRefInterfacesSimpleLocalIf;
class UTbRefInterfacesSimpleLocalIfOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace SimpleLocalIf
{
namespace OLink
{
namespace Tests
{
class FTbRefInterfacesSimpleLocalIfOLinkFixture
{
public:
	FTbRefInterfacesSimpleLocalIfOLinkFixture();
	~FTbRefInterfacesSimpleLocalIfOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetImplementation();
	UOLinkHost* GetHost();
	UTbRefInterfacesSimpleLocalIfOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace SimpleLocalIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
