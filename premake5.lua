include "Dependencies.lua"

workspace "Nebula"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Nebula/vendor/GLFW"
	include "Nebula/vendor/Glad"
group ""

group "Core"
		include "Nebula"
group ""

group "Misc"
		include "Sandbox"
group ""

group "Tools"
group ""