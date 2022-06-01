namespace UnrealBuildTool.Rules
{
	public class OrgObjectapiTestbedEditor : ModuleRules
	{
		public OrgObjectapiTestbedEditor(ReadOnlyTargetRules Target) : base(Target)
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
					"OrgObjectapiTestbedEditor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"OrgObjectapiTestbed"
				}
				);
			}
	}
}
