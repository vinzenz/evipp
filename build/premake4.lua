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

