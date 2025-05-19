
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum1InterfaceMsgBusSpec;
class ITbSame1SameEnum1Interface;
class UTbSame1SameEnum1InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace MsgBus
{
namespace Tests
{
class FTbSame1SameEnum1InterfaceMsgBusFixture
{
public:
	FTbSame1SameEnum1InterfaceMsgBusFixture();
	~FTbSame1SameEnum1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum1Interface> GetImplementation();
	UTbSame1SameEnum1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1Interface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SameEnum1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
