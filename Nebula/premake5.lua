project "Nebula"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"engine_src/**.hpp",
		"engine_src/**.cpp"
	}

	includedirs
	{
		"engine_src"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"NB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NB_DEBUG"
		runtime "Debug"
		symbols "on"
		ignoredefaultlibraries { "LIBCMT", "LIBCPMT" }
		linkoptions { "/NODEFAULTLIB:LIBCMT" }

	filter "configurations:Release"
		defines "NB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NB_DIST"
		runtime "Release"
		optimize "Full"
		symbols "off"
		flags { "LinkTimeOptimization" }
		buildoptions { "/O2" }