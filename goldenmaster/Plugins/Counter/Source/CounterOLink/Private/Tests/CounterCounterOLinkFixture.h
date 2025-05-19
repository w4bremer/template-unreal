
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"

class FCounterCounterOLinkFixture;
class ICounterCounter;
class UCounterCounterOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace OLink
{
namespace Tests
{
class FCounterCounterOLinkFixture
{
public:
	FCounterCounterOLinkFixture();
	~FCounterCounterOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounter> GetImplementation();
	UOLinkHost* GetHost();
	UCounterCounterOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounter> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
