cmake_minimum_required(VERSION 3.20)
project(IGetIt)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(deps/glfw)
add_executable(IGetIt main.cpp window.h window.cpp game_loop.cpp game_loop.h Graphics/sprite.cpp Graphics/sprite.h Util/transform.cpp Util/transform.h Graphics/texture.cpp Graphics/texture.h Graphics/texture_manager.cpp Graphics/texture_manager.h Graphics/shaders.cpp Graphics/shaders.h Graphics/sprite_renderer.cpp Graphics/sprite_renderer.h Util/camera.cpp Util/camera.h Input/Mouse.cpp Input/Mouse.h Util/Mat4.cpp Util/Mat4.h TestGraphics/WireframeRenderer.cpp TestGraphics/WireframeRenderer.h data.cpp data.h gpu_compute.cpp gpu_compute.h)

target_compile_definitions(IGetIt PUBLIC GLEW_STATIC)
target_include_directories(IGetIt PUBLIC deps/glfw/include)
target_include_directories(IGetIt PUBLIC deps/glew-2.2.0/include)
include_directories(deps/glfw/include)
include_directories(deps/glew-2.2.0/include)
target_link_libraries(IGetIt glfw)
target_link_libraries(IGetIt ${CMAKE_SOURCE_DIR}/deps/glew-2.2.0/build/lib/libglew32.a)
target_link_libraries(IGetIt opengl32)

add_custom_target(Resources
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Resources/
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/Resources
        COMMENT "copying ${CMAKE_SOURCE_DIR}/Resources to ${CMAKE_BINARY_DIR}/Resources"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

add_dependencies(IGetIt Resources)
