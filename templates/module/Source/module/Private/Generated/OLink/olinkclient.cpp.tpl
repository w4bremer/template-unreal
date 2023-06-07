{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $ifaceId := printf "%s.%s" .Module.Name .Interface.Name}}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Generated/OLink/{{$Iface}}OLinkClient.h"
#include "ApiGearSettings.h"
#include "Async/Async.h"
#include "Generated/api/{{$ModuleName}}.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

namespace
{
bool Is{{$DisplayName}}LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->OLINK_EnableDebugLog;
}
} // namespace

{{- if len .Interface.Properties }}

/**
   \brief data structure to hold the last sent property values
*/
struct {{$Iface}}PropertiesData
{
{{- range $i, $e := .Interface.Properties }}
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };
{{- end }}
};
{{- end }}
{{ if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: {{$abstractclass}}()
{{- if len .Interface.Properties }}
	, _SentData(MakePimpl<{{$Iface}}PropertiesData>())
{{- end }}
{
	m_sink = std::make_shared<FUnrealOLinkSink>("{{$ifaceId}}");
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->node()->registry().addSink(m_sink);
		AGCM->GetOLinkConnection()->linkObjectSource(m_sink->olinkObjectName());
	}

	FUnrealOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FUnrealOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);
}

void {{$Class}}::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(m_sink->olinkObjectName());
		AGCM->GetOLinkConnection()->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return {{ueVar "" .}};
}

void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	if (!m_sink->IsReady())
	{
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (Get{{Camel .Name}}_Implementation() == {{ueVar "In" .}})
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->{{ueVar "" .}} == {{ueVar "In" .}})
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "{{.Name}}"), {{ueVar "In" .}});
	_SentData->{{ueVar "" .}} = {{ueVar "In" .}};
}
{{- end }}
{{- if len .Interface.Operations }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- $returnVal := (ueReturn "" .Return)}}
{{$returnVal}} {{$Class}}::{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{- if .Return.IsVoid }}
	if (!m_sink->IsReady())
	{
		if (Is{{$DisplayName}}LogEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		}

		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc Get{{$IfaceName}}StateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "{{.Name}}"), { {{- ueVars "" .Params -}} }, Get{{$IfaceName}}StateFunc);
	{{- else }}
	if (!m_sink->IsReady())
	{
		if (Is{{$DisplayName}}LogEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		}

		return {{ ueDefault "" .Return }};
	}
	TPromise<{{$returnVal}}> Promise;
	Async(EAsyncExecution::Thread,
		[{{ueVars "" .Params }}{{if len .Params}}, {{ end }}&Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc Get{{$IfaceName}}StateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<{{$returnVal}}>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "{{.Name}}"), { {{- ueVars "" .Params -}} }, Get{{$IfaceName}}StateFunc);
		});

	return Promise.GetFuture().Get();
	{{- end }}
}
{{- end }}

void {{$Class}}::applyState(const nlohmann::json& fields)
{
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	const bool b{{Camel .Name}}Changed = fields.contains("{{.Name}}") && ({{ueVar "" .}} != fields["{{.Name}}"].get<{{ueReturn "" .}}>());
	if (b{{Camel .Name}}Changed)
	{
		{{ueVar "" .}} = fields["{{.Name}}"].get<{{ueReturn "" .}}>();
		Execute_Broadcast{{Camel .Name}}Changed(this, {{ueVar "" .}});
	}
{{- end }}
}

void {{$Class}}::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	if (signalName == "{{.Name}}")
	{
		{{- range $idx, $elem := .Params }}
		{{ueParam "" .}} = args[{{$idx}}].get<{{ueReturn "" .}}>();
		{{- end }}
		Execute_Broadcast{{Camel .Name}}(this
		{{- range $idx, $elem := .Params -}}
			, {{ueVar "" .}}
		{{- end }});
		return;
	}
{{- end }}
}
