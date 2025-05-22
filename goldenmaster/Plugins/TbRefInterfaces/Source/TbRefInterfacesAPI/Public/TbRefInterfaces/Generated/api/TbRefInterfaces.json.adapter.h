#pragma once

#include "apigear.json.adapter.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfaces_data.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfacesSimpleLocalIfInterface.h"
#include "TbRefInterfaces/Generated/api/TbRefInterfacesParentIfInterface.h"
//[]*model.Import{(*model.Import)(0xc00022a600)}
//&model.Import{NamedNode:model.NamedNode{Id:0x0, Name:"tb.ref_interfaces_import", Kind:"", Description:"", Meta:model.Meta(nil)}}
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_data.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport.json.adapter.h"
#include "TbRefInterfacesImport/Generated/api/TbRefInterfacesImport_apig.h"


static void from_json(const nlohmann::json& j, TScriptInterface<ITbRefInterfacesSimpleLocalIf>& p)
{
	Cast<ITbRefInterfacesSimpleLocalIf>(p.GetObject())->SetIntProperty(j.at("intProperty").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefInterfacesSimpleLocalIf>& p)
{
	j = nlohmann::json{
		{"intProperty", Cast<ITbRefInterfacesSimpleLocalIf>(p.GetObject())->GetIntProperty()}
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbRefInterfacesParentIf>& p)
{
	Cast<ITbRefInterfacesParentIf>(p.GetObject())->SetLocalIf(j.at("localIf").get<TScriptInterface<ITbRefInterfacesSimpleLocalIf>>());
	Cast<ITbRefInterfacesParentIf>(p.GetObject())->SetImportedIf(j.at("importedIf").get<TScriptInterface<ITbRefInterfacesImportCounter>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefInterfacesParentIf>& p)
{
	j = nlohmann::json{
		{"localIf", Cast<ITbRefInterfacesParentIf>(p.GetObject())->GetLocalIf()},
		{"importedIf", Cast<ITbRefInterfacesParentIf>(p.GetObject())->GetImportedIf()}
	};
}
