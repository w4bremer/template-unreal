{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
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
{{- $class := printf "F%sModuleFactory" $ModuleName}}
#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ScriptInterface.h"
#include "Runtime/Launch/Resources/Version.h"

class UGameInstance;
class FSubsystemCollectionBase;
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
class I{{$class}};
{{- end }}

// General Log
DECLARE_LOG_CATEGORY_EXTERN(Log{{$class}}, Log, All);

class {{ $API_MACRO }} {{$class}}
{
public:
	/** type of function for creating implementations*/
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	using F{{$class}}FactoryFunction = TFunction<TScriptInterface<I{{$class}}>(FSubsystemCollectionBase& Collection)>;
{{- end }}

	/** register factories for different types of implementations and interfaces */
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	static bool RegisterFactory(FString TypeIdentifier, F{{$class}}FactoryFunction FactoryFunction);
{{- end }}

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	static TScriptInterface<I{{$class}}> Get{{$class}}Implementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
{{- end }}

private:
{{- range .Module.Interfaces }}
{{- $iclass := printf "%s%s" $ModuleName (Camel .Name)}}
	static TMap<FString, {{$class}}::F{{$iclass}}FactoryFunction> {{$iclass}}Factories;
{{- end }}
};
