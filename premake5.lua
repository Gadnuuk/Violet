workspace "VioletEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
projectname = "%{prj.name}"

project "VioletEngine"
    location "VioletEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/" .. projectname)
    objdir ("bin-int/" .. outputdir .. "/" .. projectname)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/thirdparty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VIOLET_PLATFORM_WINDOWS",
            "VIOLET_BUILD_DLL"     
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "V_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "V_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "V_DIST"
        optimize "On"
        
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/" .. projectname)
    objdir ("bin-int/" .. outputdir .. "/" .. projectname)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "VioletEngine/thirdparty/spdlog/include",
        "VioletEngine/src"
    }

    links
    {
        "VioletEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VIOLET_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "V_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "V_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "V_DIST"
        optimize "On"