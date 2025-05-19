
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct2InterfaceMsgBusSpec;
class ITbSame2SameStruct2Interface;
class UTbSame2SameStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
class FTbSame2SameStruct2InterfaceMsgBusFixture
{
public:
	FTbSame2SameStruct2InterfaceMsgBusFixture();
	~FTbSame2SameStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2Interface> GetImplementation();
	UTbSame2SameStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2Interface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
