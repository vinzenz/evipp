--- Load extensions
dofile './util/utils.lua'

--- Definition of default targets per OS
defaultaction('linux', 'gmake')
defaultaction('windows', 'vs2010')


--- Find boost
local BOOST_LIB_DIR = os.findlib("boost_system")

if BOOST_LIB_DIR == nil then
    print( "\nWARNING: Couldn't find required boost libraries directory.\n" )
end

--- Solution
solution "evipp"
   configurations { "Debug", "Release" }
 
   --- The library evipp definition
   project "evipp"
      kind "StaticLib"
      language "C++"
      files { "../include/**.hpp", "../source/**.cpp" }
      includedirs { "../include" }
 
	  configuration { "gmake" }
         buildoptions { "-std=c++0x" }

      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
 
      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }    

    --- The unit test definition
    project "evipp_test"
        kind "ConsoleApp"
        language "C++"
        files { "../unit/**.cpp", "../unit/**.hpp" }
        links { "evipp" }
        includedirs { "../include", "../utils/libs/tut" }
        libdirs { BOOST_LIB_DIR }		

	  	configuration { "gmake" }
        	buildoptions { "-std=c++0x" }

        --- Auto run the unit tests
        configuration { "windows" }
            postbuildcommands { "evipp_test regression" }
        configuration { "not windows" }
            postbuildcommands { "./evipp_test regression" }
    
        --- Configuration settings
        configuration "Debug"
            defines { "DEBUG" }
            flags { "Symbols" }
 
        configuration "Release"
            defines { "NDEBUG" }
            flags { "Optimize" }    

