set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.0.12")
set(SDL2_INCLUDE_DIR "${SDL2_DIR}/include")
set(SDL2_INCLUDE_DIRS "${SDL2_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES "${SDL2_DIR}/lib/x64/SDL2.lib;${SDL2_DIR}/lib/x64/SDL2main.lib")
else ()
  set(SDL2_LIBRARIES "${SDL2_DIR}/lib/x86/SDL2.lib;${SDL2_DIR}/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)