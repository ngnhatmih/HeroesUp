cmake_minimum_required(VERSION 3.16)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

project(HuS)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
set (SOURCE_FILES 
    src/main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/sdl/CMakeLists.txt")
	message(FATAL_ERROR "Unable to locate the SDL3 submodule in filesystem. Try running `git submodule update --init --recursive`.")
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/sdl_image/CMakeLists.txt")
	message(FATAL_ERROR "Unable to locate the SDL3 submodule in filesystem. Try running `git submodule update --init --recursive`.")
endif()

option (SDL_TEST OFF)
set (IMGUI_SOURCE_DIR ${PROJECT_SOURCE_DIR}/vendor/imgui)

add_subdirectory(vendor/sdl)
add_subdirectory(vendor/sdl_image)
add_subdirectory(vendor/imgui)

target_include_directories(${PROJECT_NAME} 
    PRIVATE include
    PRIVATE vendor/sdl/include
    PRIVATE vendor/sdl_image/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image imgui::imgui)

# Enable lto on the target if supported (in Release mode)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif()

# Enable PIE/PIC on the target if supported
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE True)