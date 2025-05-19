
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2ManyParamInterfaceMsgBusSpec;
class ITestbed2ManyParamInterface;
class UTestbed2ManyParamInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace MsgBus
{
namespace Tests
{
class FTestbed2ManyParamInterfaceMsgBusFixture
{
public:
	FTestbed2ManyParamInterfaceMsgBusFixture();
	~FTestbed2ManyParamInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2ManyParamInterface> GetImplementation();
	UTestbed2ManyParamInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
