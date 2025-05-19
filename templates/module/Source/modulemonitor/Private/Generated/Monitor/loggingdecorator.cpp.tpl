
{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%sLoggingDecorator" $ModuleName (Camel .Interface.Name) }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "{{$ModuleName}}/Generated/Monitor/{{$Iface}}LoggingDecorator.h"
#include "{{$ModuleName}}Settings.h"
#include "{{$ModuleName}}.trace.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(Log{{$DisplayName}});

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: {{$abstractclass}}()
{
}

{{$Class}}::~{{$Class}}() = default;

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

{{- $Service := printf "I%s" $Iface }}
	setBackendService(U{{$ModuleName}}Settings::Get{{$Service}}ForLogging(Collection));
}

void {{$Class}}::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
		U{{$Iface}}Signals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
{{- end }}
{{- range .Interface.Properties }}
		BackendSignals->On{{Camel .Name}}ChangedBP.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
		BackendSignals->On{{Camel .Name}}SignalBP.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));

	// subscribe to new backend
{{- $Service := printf "I%s" $Iface }}
	BackendService = InService;
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
	U{{$Iface}}Signals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
{{- end }}
	// connect property changed signals or simple events
{{- range .Interface.Properties }}
	BackendSignals->On{{Camel .Name}}ChangedBP.AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	BackendSignals->On{{Camel .Name}}SignalBP.AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	// populate service state to proxy
{{- range .Interface.Properties }}
	{{ueVar "" .}} = BackendService->Get{{Camel .Name}}();
{{- end }}
}
{{- if .Interface.Signals }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::On{{Camel .Name}}({{ueParams "In" .Params}})
{
	{{$Iface}}Tracer::trace_signal{{Camel .Name}}({{ueVars "In" .Params}});
	_GetSignals()->Broadcast{{Camel .Name}}Signal({{ueVars "In" .Params }});
}
{{- end }}
{{- if .Interface.Properties }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	{{$Iface}}Tracer::capture_state(BackendService.GetObject(), this);
	{{ueVar "" .}} = {{ueVar "In" .}};
	_GetSignals()->Broadcast{{Camel .Name}}Changed({{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}() const
{
	return BackendService->Get{{Camel .Name}}();
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	{{$Iface}}Tracer::trace_callSet{{Camel .Name}}({{ueVar "In" .}});
	BackendService->Set{{Camel .Name}}({{ueVar "In" .}});
}
{{- end }}
{{- end }}
{{- if .Interface.Operations }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	{{ $Iface}}Tracer::trace_call{{Camel .Name}}({{ueVars "" .Params }});
	{{- if not .Return.IsVoid }}
	return BackendService->{{Camel .Name}}({{ ueVars "" .Params }});
	{{- else }}
	BackendService->{{Camel .Name}}({{ ueVars "" .Params}});
	{{- end }}
}
{{- end }}
