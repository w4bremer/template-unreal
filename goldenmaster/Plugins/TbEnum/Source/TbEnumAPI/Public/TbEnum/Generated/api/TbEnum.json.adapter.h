#pragma once

#include "apigear.json.adapter.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
//[]*model.Import(nil)

static void from_json(const nlohmann::json& j, TScriptInterface<ITbEnumEnumInterface>& p)
{
	Cast<ITbEnumEnumInterface>(p.GetObject())->SetProp0(j.at("prop0").get<ETbEnumEnum0>());
	Cast<ITbEnumEnumInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbEnumEnum1>());
	Cast<ITbEnumEnumInterface>(p.GetObject())->SetProp2(j.at("prop2").get<ETbEnumEnum2>());
	Cast<ITbEnumEnumInterface>(p.GetObject())->SetProp3(j.at("prop3").get<ETbEnumEnum3>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbEnumEnumInterface>& p)
{
	j = nlohmann::json{{"prop0", Cast<ITbEnumEnumInterface>(p.GetObject())->GetProp0()}, {"prop1", Cast<ITbEnumEnumInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbEnumEnumInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITbEnumEnumInterface>(p.GetObject())->GetProp3()}};
}
