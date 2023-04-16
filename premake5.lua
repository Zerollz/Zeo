workspace "Zeo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir ={}
IncludeDir["GLFW"] = "Zeo/vendor/GLFW/include"

include "Zeo/vendor/GLFW"

project "Zeo"
	location "Zeo"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "zopch.h"
	pchsource "Zeo/src/zopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"ZO_PLATFORM_WINDOWS",
		"ZO_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox")
	}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Zeo/vendor/spdlog/include",
		"Zeo/src"
	}

	links
	{
		"Zeo"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"ZO_PLATFORM_WINDOWS"
	}

	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZO_DIST"
		optimize "On"