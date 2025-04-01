{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sBPBase" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "Implementation/{{$Iface}}BPBase.h"
#include "{{$DisplayName}}ImplBPFixture.h"
#include "{{$ModuleName}}TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC({{$Class}}ImplSpec, "{{$ModuleName}}.{{$IfaceName}}.Impl", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}ImplBPFixture> ImplBPFixture;

// signal callbacks for testing
{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
void {{ Camel .Name }}PropertyCb({{ueParam "" .}});
{{- end }}
{{- end }}
{{- range .Interface.Signals }}
void {{ Camel .Name }}SignalCb({{ueParams "" .Params}});
{{- end }}
FDoneDelegate testDoneDelegate;

friend class {{$Class}}ImplHelper;
END_DEFINE_SPEC({{$Class}}ImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
