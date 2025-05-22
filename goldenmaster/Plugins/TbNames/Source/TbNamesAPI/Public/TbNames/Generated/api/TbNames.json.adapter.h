#pragma once

#include "apigear.json.adapter.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
//[]*model.Import(nil)

static void from_json(const nlohmann::json& j, TScriptInterface<ITbNamesNamEs>& p)
{
	Cast<ITbNamesNamEs>(p.GetObject())->SetSwitch(j.at("Switch").get<bool>());
	Cast<ITbNamesNamEs>(p.GetObject())->SetSomeProperty(j.at("SOME_PROPERTY").get<int32>());
	Cast<ITbNamesNamEs>(p.GetObject())->SetSomePoperty2(j.at("Some_Poperty2").get<int32>());
	Cast<ITbNamesNamEs>(p.GetObject())->SetEnumProperty(j.at("enum_property").get<ETbNamesEnum_With_Under_scores>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbNamesNamEs>& p)
{
	j = nlohmann::json{
		{"Switch", Cast<ITbNamesNamEs>(p.GetObject())->GetSwitch()},
		{"SOME_PROPERTY", Cast<ITbNamesNamEs>(p.GetObject())->GetSomeProperty()},
		{"Some_Poperty2", Cast<ITbNamesNamEs>(p.GetObject())->GetSomePoperty2()},
		{"enum_property", Cast<ITbNamesNamEs>(p.GetObject())->GetEnumProperty()}
	};
}
