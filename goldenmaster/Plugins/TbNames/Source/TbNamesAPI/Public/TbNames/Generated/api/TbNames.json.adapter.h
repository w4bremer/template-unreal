#pragma once

#include "apigear.json.adapter.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
//[]*model.Import(nil)

static void from_json(const nlohmann::json& j, TScriptInterface<ITbNamesNam_Es>& p)
{
	Cast<ITbNamesNam_Es>(p.GetObject())->SetSwitch(j.at("Switch").get<bool>());
	Cast<ITbNamesNam_Es>(p.GetObject())->SetSomeProperty(j.at("SOME_PROPERTY").get<int32>());
	Cast<ITbNamesNam_Es>(p.GetObject())->SetSomePoperty2(j.at("Some_Poperty2").get<int32>());
	Cast<ITbNamesNam_Es>(p.GetObject())->SetEnumProperty(j.at("enum_property").get<ETbNamesEnum_With_Under_scores>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbNamesNam_Es>& p)
{
	j = nlohmann::json{{"Switch", Cast<ITbNamesNam_Es>(p.GetObject())->GetSwitch()}, {"SOME_PROPERTY", Cast<ITbNamesNam_Es>(p.GetObject())->GetSomeProperty()}, {"Some_Poperty2", Cast<ITbNamesNam_Es>(p.GetObject())->GetSomePoperty2()}, {"enum_property", Cast<ITbNamesNam_Es>(p.GetObject())->GetEnumProperty()}};
}
