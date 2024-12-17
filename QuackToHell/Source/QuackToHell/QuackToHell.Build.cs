// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QuackToHell : ModuleRules
{
	public QuackToHell(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.AddRange(new string[] { "QuackToHell" });
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","OpenAI", "NavigationSystem", "AIModule" });
	}
}
