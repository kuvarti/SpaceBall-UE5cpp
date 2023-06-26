// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpaceBall : ModuleRules
{
	public SpaceBall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "GameplayTasks", "AIModule", "Niagara", "EnhancedInput", "UMG" });
    }
}
