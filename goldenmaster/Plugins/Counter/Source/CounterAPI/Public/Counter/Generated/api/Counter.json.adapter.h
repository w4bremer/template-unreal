#pragma once

#include "apigear.json.adapter.h"
#include "Counter/Generated/api/Counter_data.h"
#include "Counter/Generated/api/CounterCounterInterface.h"
//[]*model.Import{(*model.Import)(0xc00022a280), (*model.Import)(0xc00022a340)}
//&model.Import{NamedNode:model.NamedNode{Id:0x0, Name:"custom_types", Kind:"", Description:"", Meta:model.Meta(nil)}}
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#include "CustomTypes/Generated/api/CustomTypes.json.adapter.h"
#include "CustomTypes/Generated/api/CustomTypes_apig.h"

//&model.Import{NamedNode:model.NamedNode{Id:0x0, Name:"extern_types", Kind:"", Description:"", Meta:model.Meta(nil)}}
#include "ExternTypes/Generated/api/ExternTypes_data.h"
#include "ExternTypes/Generated/api/ExternTypes.json.adapter.h"
#include "ExternTypes/Generated/api/ExternTypes_apig.h"


static void from_json(const nlohmann::json& j, TScriptInterface<ICounterCounter>& p)
{
	Cast<ICounterCounter>(p.GetObject())->SetVector(j.at("vector").get<FCustomTypesVector3D>());
	Cast<ICounterCounter>(p.GetObject())->SetExternVector(j.at("extern_vector").get<FVector>());
	Cast<ICounterCounter>(p.GetObject())->SetVectorArray(j.at("vectorArray").get<TArray<FCustomTypesVector3D>>());
	Cast<ICounterCounter>(p.GetObject())->SetExternVectorArray(j.at("extern_vectorArray").get<TArray<FVector>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ICounterCounter>& p)
{
	j = nlohmann::json{
		{"vector", Cast<ICounterCounter>(p.GetObject())->GetVector()},
		{"extern_vector", Cast<ICounterCounter>(p.GetObject())->GetExternVector()},
		{"vectorArray", Cast<ICounterCounter>(p.GetObject())->GetVectorArray()},
		{"extern_vectorArray", Cast<ICounterCounter>(p.GetObject())->GetExternVectorArray()}
	};
}
