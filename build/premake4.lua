
local BOOST_LIB_DIR = os.findlib("boost_syste")

if BOOST_LIB_DIR == nil then
    print( "\nWARNING: Couldn't find required boost libraries directory.\n" )
end

solution "evipp"
   configurations { "Debug", "Release" }
 
   project "evipp"
      kind "StaticLib"
      language "C++"
      files { "../include/**.hpp", "../source/**.cpp" }
      includedirs { "../include" }
 
      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }    

    project "evipp_test"
        kind "ConsoleApp"
        language "C++"
        files { "../unit/**.cpp", "../unit/**.hpp" }
        links { "evipp" }
        includedirs { "../include", "../utils/libs/tut" }
        libdirs { BOOST_LIB_DIR }

        configuration { "windows" }
            postbuildcommands { "evipp_test regression" }
        configuration { "not windows" }
            postbuildcommands { "./evipp_test regression" }
    

        configuration "Debug"
            defines { "DEBUG" }
            flags { "Symbols" }
 
        configuration "Release"
            defines { "NDEBUG" }
            flags { "Optimize" }    

