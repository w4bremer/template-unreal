
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"

class UTbRefInterfacesSimpleLocalIfMsgBusSpec;
class ITbRefInterfacesSimpleLocalIf;
class UTbRefInterfacesSimpleLocalIfMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace SimpleLocalIf
{
namespace MsgBus
{
namespace Tests
{
class FTbRefInterfacesSimpleLocalIfMsgBusFixture
{
public:
	FTbRefInterfacesSimpleLocalIfMsgBusFixture();
	~FTbRefInterfacesSimpleLocalIfMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> GetImplementation();
	UTbRefInterfacesSimpleLocalIfMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesSimpleLocalIf> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleLocalIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS
