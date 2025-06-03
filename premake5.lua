workspace "Rhy"
	architecture "x64"
	startproject = "Sandbox"	

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder --> $(SolutionDir)
IncludeDir = {}
IncludeDir["GLFW"] = "Rhy/vendor/GLFW/include"
IncludeDir["Glad"] = "Rhy/vendor/Glad/include"
IncludeDir["ImGui"] = "Rhy/vendor/imgui"
IncludeDir["glm"] = "Rhy/vendor/glm"


group "Dependencies"
	include "Rhy/vendor/GLFW"
	include "Rhy/vendor/Glad"
	include "Rhy/vendor/imgui"
group ""

project "Rhy"
	location "Rhy"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	pchheader "rpch.h"
	pchsource "Rhy/src/rpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
		
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"R_PLATFORM_WINDOWS",
			"R_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "R_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "R_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "R_DIST"
		runtime "Release"
		optimize "on"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Debug"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Dist"}
		buildoptions "/utf-8"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		 "Rhy/vendor/spdlog/include",
		 "Rhy/src",
		 "Rhy/vendor",
		 "%{IncludeDir.glm}"
	}

	links
	{
		"Rhy"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"R_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "R_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "R_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "R_DIST"
		runtime "Release"
		optimize "on"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Debug"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Dist"}
		buildoptions "/utf-8"
