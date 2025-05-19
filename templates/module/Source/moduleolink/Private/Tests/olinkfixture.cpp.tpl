{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}OLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkClient.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace OLink
{
namespace Tests
{
F{{ $DisplayName }}OLinkFixture::F{{ $DisplayName }}OLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}OLinkClient>();
}

F{{ $DisplayName }}OLinkFixture::~F{{ $DisplayName }}OLinkFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}> F{{ $DisplayName }}OLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* F{{ $DisplayName }}OLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

U{{ $DisplayName }}OLinkAdapter* F{{ $DisplayName }}OLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}OLinkAdapter>();
}

UGameInstance* F{{ $DisplayName }}OLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}OLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
