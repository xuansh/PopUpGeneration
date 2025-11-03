# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PopupGenerator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PopupGenerator_autogen.dir\\ParseCache.txt"
  "PopupGenerator_autogen"
  )
endif()
