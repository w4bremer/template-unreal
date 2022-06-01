// Copyright Epic Games, Inc. All Rights Reserved

#include "ApiGearEditor.h"
#include "ISettingsModule.h"
#include "ApiGearSettings.h"

#define LOCTEXT_NAMESPACE "ApiGearEditor"

void FApiGearEditorModule::StartupModule()
{	
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)	
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear",
			LOCTEXT("ApiGearSettingsName", "ApiGear"),
			LOCTEXT("ApiGearSettingsDescription", "Project settings for ApiGear plugin"),
			GetMutableDefault<UApiGearSettings>()
		);
	}
}

void FApiGearEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
       		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear");
	}
}

IMPLEMENT_MODULE(FApiGearEditorModule, ApiGearEditor)

#undef LOCTEXT_NAMESPACE
