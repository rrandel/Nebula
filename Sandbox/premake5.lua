project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"app_src/**.hpp",
		"app_src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Nebula/vendor/spdlog/include",
		"%{wks.location}/Nebula/engine_src",
		"%{wks.location}/Nebula/vendor",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Nebula"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"NB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "NB_DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "NB_RELEASE" }
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines { "NB_DIST" }
		runtime "Release"
		optimize "Full"
		symbols "Off"
		
	filter "system:linux"
		systemversion "latest"

		defines
		{
			"NB_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines { "NB_DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "NB_RELEASE" }
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines { "NB_DIST" }
		runtime "Release"
		optimize "Full"
		symbols "Off"
