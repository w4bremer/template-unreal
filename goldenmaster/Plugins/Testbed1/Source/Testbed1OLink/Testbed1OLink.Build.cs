using UnrealBuildTool;
using System.IO;

public class Testbed1OLink : ModuleRules
{
	public Testbed1OLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		#if UE_5_2_OR_LATER 
			IWYUSupport = IWYUSupport.Full;
		#else
			bEnforceIWYU = true;
		#endif

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");
		
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/Testbed1"));

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Testbed1API",
				"Testbed1",
				"ApiGear",
				"Projects",
				"Engine",
				"JsonUtilities"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Testbed1Implementation",
				"ApiGearOLink",
				"OLinkProtocolLibrary"
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
