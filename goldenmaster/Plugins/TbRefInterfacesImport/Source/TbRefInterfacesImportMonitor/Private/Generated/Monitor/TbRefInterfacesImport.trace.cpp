#include "TbRefInterfacesImport.trace.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport.json.adapter.h"
#include "tracer.h"

TbRefInterfacesImportCounterTracer::TbRefInterfacesImportCounterTracer()
{
}

void TbRefInterfacesImportCounterTracer::capture_state(UObject* Object, ITbRefInterfacesImportCounter* obj)
{
	nlohmann::json fields_;
	Tracer::instance()->state("tb.ref_interfaces_import/Counter", fields_);
}
