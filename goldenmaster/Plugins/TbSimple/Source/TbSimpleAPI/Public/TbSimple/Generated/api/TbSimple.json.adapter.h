#pragma once

#include "apigear.json.adapter.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"
//[]*model.Import(nil)

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleVoidInterface>& p)
{
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleVoidInterface>& p)
{
	j = nlohmann::json{
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleSimpleInterface>& p)
{
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropInt32(j.at("propInt32").get<int32>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropInt64(j.at("propInt64").get<int64>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<float>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropFloat32(j.at("propFloat32").get<float>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropFloat64(j.at("propFloat64").get<double>());
	Cast<ITbSimpleSimpleInterface>(p.GetObject())->SetPropString(j.at("propString").get<FString>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleSimpleInterface>& p)
{
	j = nlohmann::json{
		{"propBool", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropBool()},
		{"propInt", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropInt()},
		{"propInt32", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropInt32()},
		{"propInt64", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropInt64()},
		{"propFloat", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropFloat()},
		{"propFloat32", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropFloat32()},
		{"propFloat64", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropFloat64()},
		{"propString", Cast<ITbSimpleSimpleInterface>(p.GetObject())->GetPropString()}
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleSimpleArrayInterface>& p)
{
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<TArray<bool>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<TArray<int32>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropInt32(j.at("propInt32").get<TArray<int32>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropInt64(j.at("propInt64").get<TArray<int64>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<TArray<float>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropFloat32(j.at("propFloat32").get<TArray<float>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropFloat64(j.at("propFloat64").get<TArray<double>>());
	Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->SetPropString(j.at("propString").get<TArray<FString>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleSimpleArrayInterface>& p)
{
	j = nlohmann::json{
		{"propBool", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropBool()},
		{"propInt", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropInt()},
		{"propInt32", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropInt32()},
		{"propInt64", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropInt64()},
		{"propFloat", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropFloat()},
		{"propFloat32", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropFloat32()},
		{"propFloat64", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropFloat64()},
		{"propString", Cast<ITbSimpleSimpleArrayInterface>(p.GetObject())->GetPropString()}
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoPropertiesInterface>& p)
{
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoPropertiesInterface>& p)
{
	j = nlohmann::json{
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoOperationsInterface>& p)
{
	Cast<ITbSimpleNoOperationsInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleNoOperationsInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoOperationsInterface>& p)
{
	j = nlohmann::json{
		{"propBool", Cast<ITbSimpleNoOperationsInterface>(p.GetObject())->GetPropBool()},
		{"propInt", Cast<ITbSimpleNoOperationsInterface>(p.GetObject())->GetPropInt()}
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoSignalsInterface>& p)
{
	Cast<ITbSimpleNoSignalsInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleNoSignalsInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoSignalsInterface>& p)
{
	j = nlohmann::json{
		{"propBool", Cast<ITbSimpleNoSignalsInterface>(p.GetObject())->GetPropBool()},
		{"propInt", Cast<ITbSimpleNoSignalsInterface>(p.GetObject())->GetPropInt()}
	};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleEmptyInterface>& p)
{
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleEmptyInterface>& p)
{
	j = nlohmann::json{
	};
}
