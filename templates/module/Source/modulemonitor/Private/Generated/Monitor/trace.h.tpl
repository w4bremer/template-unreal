{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_apig.h"
{{- range .Module.Interfaces }}
{{- $class := printf "%s%sTracer" $ModuleName (Camel .Name) }}
{{- $Name := (Camel .Name)}}

class {{$class}}
{
public:
	{{$class}}();
	static void capture_state(UObject* Object, I{{$ModuleName}}{{$Name}}* obj);
{{- range .Properties }}
{{- if not .IsReadOnly }}
	static void trace_callSet{{Camel .Name}}({{ueParam "In" .}});
{{- end }}
{{- end }}
{{- range .Signals }}
	static void trace_signal{{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- range .Operations}}
	static void trace_call{{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
};
{{- end }}
