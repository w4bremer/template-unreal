
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoOperationsInterfaceMsgBusSpec;
class ITbSimpleNoOperationsInterface;
class UTbSimpleNoOperationsInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbSimpleNoOperationsInterfaceMsgBusFixture
{
public:
	FTbSimpleNoOperationsInterfaceMsgBusFixture();
	~FTbSimpleNoOperationsInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoOperationsInterface> GetImplementation();
	UTbSimpleNoOperationsInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace NoOperationsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
