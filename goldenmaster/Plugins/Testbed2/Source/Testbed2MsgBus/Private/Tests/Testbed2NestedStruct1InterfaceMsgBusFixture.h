
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct1InterfaceMsgBusSpec;
class ITestbed2NestedStruct1Interface;
class UTestbed2NestedStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace MsgBus
{
namespace Tests
{
class FTestbed2NestedStruct1InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct1InterfaceMsgBusFixture();
	~FTestbed2NestedStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1Interface> GetImplementation();
	UTestbed2NestedStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1Interface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace NestedStruct1Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
