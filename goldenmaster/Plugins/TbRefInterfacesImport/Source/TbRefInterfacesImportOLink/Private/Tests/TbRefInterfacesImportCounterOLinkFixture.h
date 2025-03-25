
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"

class FTbRefInterfacesImportCounterOLinkFixture;
class ITbRefInterfacesImportCounter;
class UTbRefInterfacesImportCounterOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfacesImport
{
namespace Counter
{
namespace OLink
{
namespace Tests
{
class FTbRefInterfacesImportCounterOLinkFixture
{
public:
	FTbRefInterfacesImportCounterOLinkFixture();
	~FTbRefInterfacesImportCounterOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesImportCounter> GetImplementation();
	UOLinkHost* GetHost();
	UTbRefInterfacesImportCounterOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesImportCounter> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace Counter
} // namespace TbRefInterfacesImport

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
