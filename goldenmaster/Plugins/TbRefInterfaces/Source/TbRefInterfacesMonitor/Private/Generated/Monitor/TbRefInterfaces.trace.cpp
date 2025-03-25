#include "TbRefInterfaces.trace.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces.json.adapter.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport.json.adapter.h"
#include "tracer.h"

TbRefInterfacesSimpleLocalIfTracer::TbRefInterfacesSimpleLocalIfTracer()
{
}

void TbRefInterfacesSimpleLocalIfTracer::capture_state(UObject* Object, ITbRefInterfacesSimpleLocalIf* obj)
{
	nlohmann::json fields_;
	fields_["intProperty"] = obj->GetIntProperty();
	Tracer::instance()->state("tb.ref_interfaces/SimpleLocalIf", fields_);
}
void TbRefInterfacesSimpleLocalIfTracer::trace_callSetIntProperty(int32 InIntProperty)
{
	nlohmann::json fields_;
	fields_["intProperty"] = InIntProperty;
	Tracer::instance()->call("tb.ref_interfaces/SimpleLocalIf#_set", fields_);
}

void TbRefInterfacesSimpleLocalIfTracer::trace_signalIntSignal(int32 Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_interfaces/SimpleLocalIf#intSignal", fields_);
}

void TbRefInterfacesSimpleLocalIfTracer::trace_callIntMethod(int32 Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_interfaces/SimpleLocalIf#intMethod", fields_);
}

TbRefInterfacesParentIfTracer::TbRefInterfacesParentIfTracer()
{
}

void TbRefInterfacesParentIfTracer::capture_state(UObject* Object, ITbRefInterfacesParentIf* obj)
{
	nlohmann::json fields_;
	fields_["localIf"] = obj->GetLocalIf();
	fields_["importedIf"] = obj->GetImportedIf();
	Tracer::instance()->state("tb.ref_interfaces/ParentIf", fields_);
}
void TbRefInterfacesParentIfTracer::trace_callSetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	nlohmann::json fields_;
	fields_["localIf"] = InLocalIf;
	Tracer::instance()->call("tb.ref_interfaces/ParentIf#_set", fields_);
}
void TbRefInterfacesParentIfTracer::trace_callSetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	nlohmann::json fields_;
	fields_["importedIf"] = InImportedIf;
	Tracer::instance()->call("tb.ref_interfaces/ParentIf#_set", fields_);
}

void TbRefInterfacesParentIfTracer::trace_signalLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_interfaces/ParentIf#localIfSignal", fields_);
}

void TbRefInterfacesParentIfTracer::trace_signalImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_interfaces/ParentIf#importedIfSignal", fields_);
}

void TbRefInterfacesParentIfTracer::trace_callLocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_interfaces/ParentIf#localIfMethod", fields_);
}

void TbRefInterfacesParentIfTracer::trace_callImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_interfaces/ParentIf#importedIfMethod", fields_);
}
