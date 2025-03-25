#pragma once

#include "TbRefInterfaces/Generated/api/TbRefInterfaces_apig.h"

class TbRefInterfacesSimpleLocalIfTracer
{
public:
	TbRefInterfacesSimpleLocalIfTracer();
	static void capture_state(UObject* Object, ITbRefInterfacesSimpleLocalIf* obj);
	static void trace_callSetIntProperty(int32 InIntProperty);
	static void trace_signalIntSignal(int32 Param);
	static void trace_callIntMethod(int32 Param);
};

class TbRefInterfacesParentIfTracer
{
public:
	TbRefInterfacesParentIfTracer();
	static void capture_state(UObject* Object, ITbRefInterfacesParentIf* obj);
	static void trace_callSetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf);
	static void trace_callSetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf);
	static void trace_signalLocalIfSignal(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);
	static void trace_signalImportedIfSignal(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);
	static void trace_callLocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param);
	static void trace_callImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param);
};
