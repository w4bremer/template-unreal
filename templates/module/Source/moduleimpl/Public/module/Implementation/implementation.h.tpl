{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sIMPLEMENTATION_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sImplementation" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
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
#pragma once

#include "CoreMinimal.h"
#include "{{$ModuleName}}/Generated/api/Abstract{{$Iface}}.h"
#include "{{$Iface}}.generated.h"

UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}
{
	GENERATED_BODY()
public:
	virtual ~{{$Class}}();

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "" .}}) override;
{{- end}}
{{ end }}
{{- if len .Interface.Properties }}
	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Properties")
	void _ResetProperties();
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if ne $i 0 }}{{nl}}{{ end }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- end }}
};
