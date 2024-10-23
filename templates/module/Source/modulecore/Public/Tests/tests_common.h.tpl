{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name}}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 

{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{$class }} {{$API_MACRO}} createTest{{$class }}();

TArray<{{$class}}> {{$API_MACRO}} createTest{{$class }}Array();
{{ end }}
#endif // WITH_DEV_AUTOMATION_TESTS