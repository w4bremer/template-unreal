#pragma once

#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_apig.h"

class TbRefInterfacesImportCounterTracer
{
public:
	TbRefInterfacesImportCounterTracer();
	static void capture_state(UObject* Object, ITbRefInterfacesImportCounter* obj);
};
