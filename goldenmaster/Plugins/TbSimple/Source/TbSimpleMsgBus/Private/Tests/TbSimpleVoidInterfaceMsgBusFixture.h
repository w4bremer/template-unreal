
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleVoidInterfaceMsgBusSpec;
class ITbSimpleVoidInterface;
class UTbSimpleVoidInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbSimpleVoidInterfaceMsgBusFixture
{
public:
	FTbSimpleVoidInterfaceMsgBusFixture();
	~FTbSimpleVoidInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterface> GetImplementation();
	UTbSimpleVoidInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
