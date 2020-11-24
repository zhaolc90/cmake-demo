cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.0.12")
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES "${SDL2_DIR}/lib/x64/SDL2.lib;${SDL2_DIR}/lib/x64/SDL2main.lib")
else ()
  set(SDL2_LIBRARIES "${SDL2_DIR}/lib/x86/SDL2.lib;${SDL2_DIR}/lib/x86/SDL2main.lib")
endif ()

# find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/SDL2-2.0.12/include
)