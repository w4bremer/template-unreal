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

#include "TbRefInterfaces/Implementation/TbRefInterfacesParentIf.h"

UTbRefInterfacesParentIfImplementation::~UTbRefInterfacesParentIfImplementation() = default;
TScriptInterface<ITbRefInterfacesSimpleLocalIf> UTbRefInterfacesParentIfImplementation::GetLocalIf() const
{
	return LocalIf;
}

void UTbRefInterfacesParentIfImplementation::SetLocalIf(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& InLocalIf)
{
	if (LocalIf != InLocalIf)
	{
		LocalIf = InLocalIf;
		_GetSignals()->BroadcastLocalIfChanged(LocalIf);
	}
}
TScriptInterface<ITbRefInterfacesImportCounter> UTbRefInterfacesParentIfImplementation::GetImportedIf() const
{
	return ImportedIf;
}

void UTbRefInterfacesParentIfImplementation::SetImportedIf(const TScriptInterface<ITbRefInterfacesImportCounter>& InImportedIf)
{
	if (ImportedIf != InImportedIf)
	{
		ImportedIf = InImportedIf;
		_GetSignals()->BroadcastImportedIfChanged(ImportedIf);
	}
}

TScriptInterface<ITbRefInterfacesSimpleLocalIf> UTbRefInterfacesParentIfImplementation::LocalIfMethod(const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
}

TScriptInterface<ITbRefInterfacesImportCounter> UTbRefInterfacesParentIfImplementation::ImportedIfMethod(const TScriptInterface<ITbRefInterfacesImportCounter>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefInterfacesImportCounter>();
}

void UTbRefInterfacesParentIfImplementation::_ResetProperties()
{
	if (LocalIf != TScriptInterface<ITbRefInterfacesSimpleLocalIf>())
	{
		LocalIf = TScriptInterface<ITbRefInterfacesSimpleLocalIf>();
		_GetSignals()->BroadcastLocalIfChanged(LocalIf);
	}
	if (ImportedIf != TScriptInterface<ITbRefInterfacesImportCounter>())
	{
		ImportedIf = TScriptInterface<ITbRefInterfacesImportCounter>();
		_GetSignals()->BroadcastImportedIfChanged(ImportedIf);
	}
}
