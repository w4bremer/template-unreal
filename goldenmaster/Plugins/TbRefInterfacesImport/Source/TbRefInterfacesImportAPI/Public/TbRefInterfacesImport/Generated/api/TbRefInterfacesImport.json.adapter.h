#pragma once

#include "apigear.json.adapter.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImportCounterInterface.h"
//[]*model.Import(nil)

static void from_json(const nlohmann::json& j, TScriptInterface<ITbRefInterfacesImportCounter>& p)
{
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefInterfacesImportCounter>& p)
{
	j = nlohmann::json{
	};
}
