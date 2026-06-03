// War GAS - SIMAO

using UnrealBuildTool;
using System.Collections.Generic;

public class WarGASEditorTarget : TargetRules
{
	public WarGASEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("WarGAS");
	}
}
