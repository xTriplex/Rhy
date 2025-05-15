workspace "Rhy"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Rhy"
	location "Rhy"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		 "%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"R_PLATFORM_WINDOWS",
			"R_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "R_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "R_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "R_DIST"
		optimize "On"

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
		 "Rhy/src"
	}

	links
	{
		"Rhy"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"R_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "R_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "R_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "R_DIST"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Debug"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Dist"}
		buildoptions "/utf-8"