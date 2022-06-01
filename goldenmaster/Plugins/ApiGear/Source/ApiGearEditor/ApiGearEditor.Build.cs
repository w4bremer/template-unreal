using System.IO;
using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class ApiGearEditor : ModuleRules
	{
		public ApiGearEditor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"ApiGearEditor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"ApiGear"
				}
				);
			}
	}
}
