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

#include "TbRefInterfacesEditor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "TbRefInterfacesSettings.h"
#include "TbRefInterfacesConnectionSettings.h"

#define LOCTEXT_NAMESPACE "TbRefInterfacesEditor"

void FTbRefInterfacesEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbRefInterfaces", LOCTEXT("TbRefInterfacesSettingsName", "ApiGear TbRefInterfaces"), LOCTEXT("TbRefInterfacesSettingsDescription", "Project settings for ApiGear TbRefInterfaces plugin"), GetMutableDefault<UTbRefInterfacesSettings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("TbRefInterfacesSettings", FOnGetDetailCustomizationInstance::CreateStatic(&FTbRefInterfacesConnectionSettingsDetails::MakeInstance));
}

void FTbRefInterfacesEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbRefInterfaces");
	}
}

IMPLEMENT_MODULE(FTbRefInterfacesEditorModule, TbRefInterfacesEditor)

#undef LOCTEXT_NAMESPACE
