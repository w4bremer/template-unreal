
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"

class UTbRefInterfacesImportCounterMsgBusSpec;
class ITbRefInterfacesImportCounter;
class UTbRefInterfacesImportCounterMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefInterfacesImport
{
namespace Counter
{
namespace MsgBus
{
namespace Tests
{
class FTbRefInterfacesImportCounterMsgBusFixture
{
public:
	FTbRefInterfacesImportCounterMsgBusFixture();
	~FTbRefInterfacesImportCounterMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefInterfacesImportCounter> GetImplementation();
	UTbRefInterfacesImportCounterMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefInterfacesImportCounter> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace Counter
} // namespace TbRefInterfacesImport

#endif // WITH_DEV_AUTOMATION_TESTS
