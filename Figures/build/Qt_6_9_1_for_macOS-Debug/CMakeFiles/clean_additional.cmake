# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Figures_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Figures_autogen.dir/ParseCache.txt"
  "Figures_autogen"
  )
endif()
