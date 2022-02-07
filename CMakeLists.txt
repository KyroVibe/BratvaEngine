cmake_minimum_required(VERSION 3.20)
project(IGetIt)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(deps/glfw)
#add_subdirectory(deps/glew/build/cmake)
add_executable(IGetIt main.cpp window.h window.cpp game_loop.cpp game_loop.h Graphics/sprite.cpp Graphics/sprite.h Util/transform.cpp Util/transform.h Graphics/texture.cpp Graphics/texture.h Graphics/texture_manager.cpp Graphics/texture_manager.h Graphics/shaders.cpp Graphics/shaders.h Graphics/sprite_renderer.cpp Graphics/sprite_renderer.h Util/camera.cpp Util/camera.h Input/Mouse.cpp Input/Mouse.h Util/Mat4.cpp Util/Mat4.h TestGraphics/WireframeRenderer.cpp TestGraphics/WireframeRenderer.h data.cpp data.h gpu_compute.cpp gpu_compute.h)

target_compile_definitions(IGetIt PUBLIC GLEW_STATIC)
target_include_directories(IGetIt PUBLIC deps/glfw/include)
#target_include_directories(IGetIt PUBLIC deps/glew-2.2.0/include)
target_link_libraries(IGetIt glfw)
#target_link_libraries(IGetIt ${CMAKE_SOURCE_DIR}/deps/glew-2.2.0/build/lib/Release/libglew32.lib)
target_link_libraries(IGetIt libGL.so)
target_link_libraries(IGetIt libGLEW.a)

