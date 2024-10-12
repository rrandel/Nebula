project "Nebula"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nbpch.hpp"
	pchsource "engine_src/nbpch.cpp"

	files
	{
		"engine_src/**.hpp",
		"engine_src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"engine_src",
		"vendor/spdlog/include",
		"Nebula/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
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

	filter "configurations:Release"
		defines "NB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NB_DIST"
		runtime "Release"
		optimize "Full"
		symbols "off"
		
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
