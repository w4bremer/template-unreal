
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

class FTbRefInterfacesParentIfOLinkFixture;
class ITbRefInterfacesParentIf;
class UTbRefInterfacesParentIfOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace ParentIf
{
namespace OLink
{
namespace Tests
{
class FTbRefInterfacesParentIfOLinkFixture
{
public:
	FTbRefInterfacesParentIfOLinkFixture();
	~FTbRefInterfacesParentIfOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesParentIf> GetImplementation();
	UOLinkHost* GetHost();
	UTbRefInterfacesParentIfOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesParentIf> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace ParentIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
