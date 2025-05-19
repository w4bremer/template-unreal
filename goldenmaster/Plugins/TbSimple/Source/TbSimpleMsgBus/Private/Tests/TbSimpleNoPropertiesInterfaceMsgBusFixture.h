
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoPropertiesInterfaceMsgBusSpec;
class ITbSimpleNoPropertiesInterface;
class UTbSimpleNoPropertiesInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbSimpleNoPropertiesInterfaceMsgBusFixture
{
public:
	FTbSimpleNoPropertiesInterfaceMsgBusFixture();
	~FTbSimpleNoPropertiesInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterface> GetImplementation();
	UTbSimpleNoPropertiesInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace NoPropertiesInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
