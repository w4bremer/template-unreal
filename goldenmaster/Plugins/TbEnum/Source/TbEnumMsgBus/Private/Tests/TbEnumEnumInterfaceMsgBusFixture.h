
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceMsgBusSpec;
class ITbEnumEnumInterface;
class UTbEnumEnumInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbEnumEnumInterfaceMsgBusFixture
{
public:
	FTbEnumEnumInterfaceMsgBusFixture();
	~FTbEnumEnumInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterface> GetImplementation();
	UTbEnumEnumInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
