{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sBPBase" $DisplayName}}
#include "{{$DisplayName}}ImplBPFixture.h"
#include "{{$DisplayName}}ImplBP.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void {{$Class}}ImplHelper::SetSpec({{$Class}}ImplSpec* InSpec)
{
	Spec = InSpec;
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	Spec->{{ Camel .Name }}PropertyCb({{ueVar "" .}});
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}ImplHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	Spec->{{ Camel .Name }}SignalCb({{ueVars "" .Params}});
}
{{- end }}

F{{ $DisplayName }}ImplBPFixture::F{{ $DisplayName }}ImplBPFixture()
{
	testImplementation = NewObject<{{$Class}}>();
	Helper = NewObject<{{$Class}}ImplHelper>();
}

F{{ $DisplayName }}ImplBPFixture::~F{{ $DisplayName }}ImplBPFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}ImplBPFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<{{$Class}}ImplHelper> F{{ $DisplayName }}ImplBPFixture::GetHelper()
{
	return Helper;
}

void F{{ $DisplayName }}ImplBPFixture::CleanUp()
{
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void {{$Class}}ImplHelper::SetSpec({{$Class}}ImplSpec* /* InSpec */)
{
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	(void){{ueVar "" .}};
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}ImplHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	{{- range $i, $e := .Params }}
	(void){{ueVar "" .}};
	{{- end }}
}
{{- end }}
#endif // WITH_DEV_AUTOMATION_TESTS
