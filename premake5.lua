workspace "Ettin"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ettin"
    location "Ettin"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "Etpch.h"
    pchsource "Ettin/src/Etpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    externalincludedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/SDL2/include"
    }

    syslibdirs
    {
        "%{prj.name}/vendor/SDL2/lib/x64"
    }

    links
    {
        "SDL2",
        "SDL2main"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ET_PLATFORM_WINDOWS",
            "ET_BUILD_DLL"
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "ET_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ET_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ET_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Ettin/vendor/spdlog/include",
        "Ettin/src"
    }

    externalincludedirs
    {
        "Ettin/vendor/spdlog/include",
        "Ettin/src",
        "Ettin/vendor/SDL2/include"
    }

    syslibdirs
    {
        "Ettin/vendor/SDL2/lib/x64"
    }

    links
    {
        "SDL2",
        "SDL2main",
        "Ettin"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ET_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ET_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ET_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ET_DIST"
        optimize "On"

