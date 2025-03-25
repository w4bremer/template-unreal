
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"

class UTbRefInterfacesParentIfMsgBusSpec;
class ITbRefInterfacesParentIf;
class UTbRefInterfacesParentIfMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfaces
{
namespace ParentIf
{
namespace MsgBus
{
namespace Tests
{
class FTbRefInterfacesParentIfMsgBusFixture
{
public:
	FTbRefInterfacesParentIfMsgBusFixture();
	~FTbRefInterfacesParentIfMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesParentIf> GetImplementation();
	UTbRefInterfacesParentIfMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesParentIf> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace ParentIf
} // namespace TbRefInterfaces

#endif // WITH_DEV_AUTOMATION_TESTS
