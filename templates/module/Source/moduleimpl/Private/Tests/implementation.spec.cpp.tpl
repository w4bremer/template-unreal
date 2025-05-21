{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$ModuleName}}/Implementation/{{$Iface}}.h"
#include "{{$DisplayName}}ImplFixture.h"
#include "{{$ModuleName}}/Tests/{{$ModuleName}}TestsCommon.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC({{$Class}}ImplSpec, "{{$ModuleName}}.{{$IfaceName}}.Impl", {{$ModuleName}}TestFilterMask);

TSharedPtr<F{{$DisplayName}}ImplFixture> ImplFixture;

END_DEFINE_SPEC({{$Class}}ImplSpec);

void {{$Class}}ImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<F{{$DisplayName}}ImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});
{{- range .Interface.Properties }}

	It("Property.{{ Camel .Name }}.Default", [this]()
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
	{{- if not .IsReadOnly }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), {{ueDefault "" .}});
	{{- end }}
	});

	{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) (not (eq .KindType "interface")) }}

	LatentIt("Property.{{ Camel .Name }}.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);

		U{{$Iface}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}Changed.AddLambda([this, TestDone]({{ueParam "In" .}})
			{
			{{ueType "" .}} TestValue = {{ueDefault "" .}};
			// use different test value
			{{- if .IsArray }}
			{{- if or .IsPrimitive (eq .KindType "enum") }}
			TestValue.Add({{ ueTestValue "" .}});
			{{- else }}
			{{- $type := ""}}
			{{- if not (eq .Import "") }}
			{{- $type = printf "F%s%s" (Camel .Import) .Type }}
			{{- else }}
			{{- $type = printf "F%s%s" $ModuleName .Type }}
			{{- end }}
			TestValue = createTest{{ $type }}Array();
			{{- end }}
			{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
			TestValue = createTest{{ ueType "" . }}();
			{{- else }}
			TestValue = {{ ueTestValue "" . }};
			{{- end }}
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		ImplFixture->GetImplementation()->Set{{Camel .Name}}(TestValue);
	});

	LatentIt("Property.{{ Camel .Name }}.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		U{{$Iface}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb);
		// use different test value
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		ImplFixture->GetImplementation()->Set{{Camel .Name}}(TestValue);
	});
	{{- end }}

{{- end }}

{{- range .Interface.Operations }}

	It("Operation.{{ Camel .Name }}", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->{{Camel .Name}}(
			{{- range $i, $e := .Params -}}
			{{ if $i }}, {{end}}{{ueDefault "" .}}
			{{- end -}}
		);
	});

{{- end }}

{{- range .Interface.Signals }}

	LatentIt("Signal.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		U{{$Iface}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}Signal.AddLambda([this, TestDone]({{ueParams "In" .Params}})
			{
			// known test value
			{{- range $i, $e := .Params -}}
			{{- if not (eq .KindType "extern") }}
			{{- if .IsArray }}
			{{- if or .IsPrimitive (eq .KindType "enum") }}
			{{ueType "" .}} {{ueVar "" .}}TestValue = {{ueDefault "" .}}; // default value
			{{ueVar "" .}}TestValue.Add({{ ueTestValue "" .}});
			{{- else }}
			{{- $type := ""}}
			{{- if not (eq .Import "") }}
			{{- $type = printf "F%s%s" (Camel .Import) .Type }}
			{{- else }}
			{{- $type = printf "F%s%s" $ModuleName .Type }}
			{{- end }}
			{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
			{{- end }}
			{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
			{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
			{{- else }}
			{{ueType "" .}} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
			{{- end }}
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), {{ueVar "In" .}}, {{ueVar "" .}}TestValue);
			{{- end }}
			{{- end }}
			TestDone.Execute();
		});

		// use different test value
		{{- range $i, $e := .Params -}}
		{{- if not (eq .KindType "extern") }}
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		{{ueType "" .}} {{ueVar "" .}}TestValue = {{ueDefault "" .}}; // default value
		{{ueVar "" .}}TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
		{{- end }}
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueDefault "" . }};
		{{- end }}
		{{- end }}
		{{$Iface}}Signals->Broadcast{{Camel .Name}}Signal(
			{{- range $i, $e := .Params -}}
			{{- if $i }}, {{ end }}{{ueVar "" .}}TestValue
			{{- end -}});
	});

	LatentIt("Signal.{{ Camel .Name }}BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		U{{$Iface}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}SignalCb);

		// use different test value
		{{- range $i, $e := .Params -}}
		{{- if not (eq .KindType "extern") }}
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		{{ueType "" .}} {{ueVar "" .}}TestValue = {{ueDefault "" .}}; // default value
		{{ueVar "" .}}TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
		{{- end }}
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueDefault "" . }};
		{{- end }}
		{{- end }}
		{{$Iface}}Signals->Broadcast{{Camel .Name}}Signal(
			{{- range $i, $e := .Params -}}
			{{- if $i }}, {{ end }}{{ueVar "" .}}TestValue
			{{- end -}});
	});

{{- end }}
}

#endif // WITH_DEV_AUTOMATION_TESTS
