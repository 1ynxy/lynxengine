cmake_minimum_required(VERSION 3.5)
project(lynxengine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(lynxengine
  src/resource/asset/req/lodepng.cpp

  src/data/colour.cpp

  src/core/core.cpp
  src/core/time.cpp
  src/core/input.cpp
  src/core/debug.cpp
  src/core/file.cpp
  src/core/config.cpp
  src/core/display.cpp

  src/resource/resource.cpp
  src/resource/asset.cpp
  src/resource/asset/sprite.cpp
  src/resource/asset/shader.cpp
  src/resource/asset/mesh.cpp
  src/resource/asset/rendertexture.cpp

  src/render/render.cpp
  src/render/compositor.cpp

  src/ces/scene.cpp
  src/ces/entity.cpp
  src/ces/component.cpp
  src/ces/component/transform.cpp
  src/ces/component/camera.cpp
  src/ces/component/controller.cpp
  src/ces/component/meshrenderer.cpp
)

target_include_directories(lynxengine PRIVATE lynxengine/)
target_include_directories(lynxengine PRIVATE src/)

find_package(Threads REQUIRED)

include_directories(PUBLIC contrib/glad/)
include_directories(PUBLIC contrib/glm/)

target_link_libraries(lynxengine
  PRIVATE
    Threads::Threads
  PUBLIC
    glad
    glfw
)

set_target_properties(lynxengine PROPERTIES PUBLIC_HEADER lynxengine/lynxengine.h)
