// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Programming2 : ModuleRules
{
	public Programming2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
