{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sBPBase" $DisplayName}}
{{- $Iface := printf "I%s%sInterface" $ModuleName $IfaceName }}

#include "Implementation/{{$DisplayName}}BPBase.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

{{- if .Interface.Operations}}{{ nl }}
class F{{$Iface}}LatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	F{{$Iface}}LatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
		bInProgress = false;
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};
{{- end}}

{{- if or (len .Interface.Properties) (len .Interface.Signals) }}
{{- nl }}
U{{$DisplayName}}Signals* {{$Class}}::_GetSignals_Implementation()
{
	if (!{{$DisplayName}}Signals)
	{
		{{$DisplayName}}Signals = NewObject<U{{$DisplayName}}Signals>();
	}
	return {{$DisplayName}}Signals;
}
{{- end }}

{{$Class}}::~{{$Class}}() = default;

{{- range .Interface.Properties }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Private() const
{
	return Execute_Get{{Camel .Name}}(this);
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return {{ueVar "" .}};
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}_Private({{ueParam "In" .}})
{
	Execute_Set{{Camel .Name}}(this, {{ueVar "In" .}});
}

void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	if ({{ueVar "" .}} != {{ueVar "In" .}})
	{
		{{ueVar "" .}} = {{ueVar "In" .}};
		Execute__GetSignals(this)->On{{Camel .Name}}Changed.Broadcast({{ueVar "" .}});
	}
}
{{- end }}
{{- else }}
{{- end }}
{{- range .Interface.Operations }}{{ nl }}
{{- if not .Return.IsVoid }}
void {{$Class}}::{{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{ if len .Params }}, {{end}}{{ueParams "" .Params}})
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		F{{$Iface}}LatentAction* oldRequest = LatentActionManager.FindExistingAction<F{{$Iface}}LatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		F{{$Iface}}LatentAction* CompletionAction = new F{{$Iface}}LatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_{{Camel .Name}}(this{{ if len .Params }}, {{end}}{{ueVars "" .Params}});
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[{{range .Params}}{{ueVar "" .}}, {{ end }}this, &Result, CompletionAction]()
				{
				Result = Execute_{{Camel .Name}}(this{{ if len .Params }}, {{end}}{{ueVars "" .Params}});
				CompletionAction->Cancel();
			});
		}
	}
}
{{- nl }}
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{- range .Params }}
	(void){{ueVar "" .}};
	{{- end }}
	// do business logic here
	{{- if not .Return.IsVoid }}
	return {{ueDefault "" .Return}};
	{{- end }}
}
{{- else }}
{{- end }}
