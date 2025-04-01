{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sBPBase" $DisplayName}}
{{- $Iface := printf "I%s%sInterface" $ModuleName $IfaceName }}

#pragma once

#include "CoreMinimal.h"
#include "Generated/api/{{$DisplayName}}Interface.h"
#include "{{$DisplayName}}BPBase.generated.h"

UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UObject, public {{ $Iface }}
{
	GENERATED_BODY()
public:
	virtual ~{{$Class}}();

{{- if or (len .Interface.Properties) (len .Interface.Signals) }}
{{- nl }}
	// signals
	virtual U{{$DisplayName}}Signals* _GetSignals_Implementation() override;
{{- end }}

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}_Implementation({{ueParam "" .}}) override;
{{- end}}
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if ne $i 0 }}{{nl}}{{ end }}
{{- if not .Return.IsVoid }}
	virtual void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) override;
{{- end }}
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
{{- end }}

protected:
	// properties - local copy
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	UPROPERTY(EditAnywhere, BlueprintGetter = Get{{Camel .Name}}_Private, {{ if not .IsReadOnly -}} BlueprintSetter = Set{{Camel .Name}}_Private, {{ end }}Category = "{{$Category}}")
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };

	UFUNCTION(BlueprintGetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	{{ueReturn "" .}} Get{{Camel .Name}}_Private() const;
{{- if not .IsReadOnly }}{{nl}}
	UFUNCTION(BlueprintSetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	void Set{{Camel .Name}}_Private({{ueParam "In" .}});
{{- end }}
{{- end }}

private:
{{- if or (len .Interface.Properties) (len .Interface.Signals) }}
	// signals
	UPROPERTY()
	U{{$DisplayName}}Signals* {{$DisplayName}}Signals;
{{- end }}
};
