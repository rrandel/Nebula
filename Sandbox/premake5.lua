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
		"%{wks.location}/Nebula/engine_src",
		"%{wks.location}/Nebula/dependencies"
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
		ignoredefaultlibraries { "LIBCMT", "LIBCPMT" }
		linkoptions { "/NODEFAULTLIB:LIBCMT" }

	filter "configurations:Release"
		defines { "NB_RELEASE" }
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines { "NB_DIST" }
		runtime "Release"
		optimize "Full"
		symbols "Off"
		flags { "LinkTimeOptimization" }
		buildoptions { "/O2" }