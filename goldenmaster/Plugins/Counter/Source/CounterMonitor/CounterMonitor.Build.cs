using UnrealBuildTool;
using System.IO;

public class CounterMonitor : ModuleRules
{
	public CounterMonitor(ReadOnlyTargetRules Target) : base(Target)
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
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/Counter"));

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
				"CounterAPI",
				"CounterCore",
				"ApiGear",
				"Projects",
				"Engine",
				"JsonUtilities",
				"CustomTypesCore", 
				"ExternTypesCore"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"CustomTypesAPI",
				"ExternTypesAPI",
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